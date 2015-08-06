#include <rainbowduino.h>
#include "dot.h"
#include "hungerscorer.h"
#include "snake.h"
#include "world.h"

#define HUNGER_THRESHOLD 1000

HungerScorer::HungerScorer(World* world, Snake* snake, Dot* dot) : m_world(world), m_snake(snake), m_dot(dot) {
}

double HungerScorer::weigh(Coordinate coordinate) {
  if (!m_world->is_valid(m_dot->position))
  {
    return 0;
  }

  if (!m_dot->is_ripe())
  {
    // If the candidate is the dot, but we are still full, avoid it.
    // Otherwise, we don't care.
    return coordinate == m_dot->position ? -100 : 0;
  }

  Coordinate head = m_snake->get_segment_position(0);

  int snake_distance = abs(head.z - m_dot->position.z) + abs(head.x - m_dot->position.x) + abs(head.y - m_dot->position.y);
  int candidate_distance = abs(coordinate.z - m_dot->position.z) + abs(coordinate.x - m_dot->position.x) + abs(coordinate.y - m_dot->position.y);
  return candidate_distance < snake_distance ? m_dot->get_age(): -m_dot->get_age();
}

