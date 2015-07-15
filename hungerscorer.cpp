#include <rainbowduino.h>
#include "hungerscorer.h"
#include "snake.h"
#include "world.h"

#define HUNGER_THRESHOLD 1000

HungerScorer::HungerScorer(World* world, Snake* snake) : m_snake(snake), m_world(world) {
}

double HungerScorer::weigh(Coordinate coordinate) {
  Coordinate dot = m_world->get_dot_coordinate();
  if (!m_world->is_valid(dot))
  {
    return 0;
  }

  if (m_snake->hunger < 0)
  {
    // If the candidate is the dot, but we are still full, avoid it.
    // Otherwise, we don't care.
    return coordinate == dot ? -100 : 0;
  }

  Coordinate head = m_snake->get_head();

  int snake_distance = abs(head.z - dot.z) + abs(head.x - dot.x) + abs(head.y - dot.y);
  int candidate_distance = abs(coordinate.z - dot.z) + abs(coordinate.x - dot.x) + abs(coordinate.y - dot.y);
  return candidate_distance < snake_distance ? m_snake->hunger: -m_snake->hunger;
}

