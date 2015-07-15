#include <rainbowduino.h>
#include "hungerrule.h"
#include "snake.h"
#include "world.h"

HungerRule::HungerRule(World* world, Snake* snake) : m_snake(snake), m_world(world) {
  Serial.begin(9600);
}

void HungerRule::execute() {
  if (m_dot_last_seen != m_world->get_dot_coordinate())
  {
    m_dot_last_seen = m_world->get_dot_coordinate();
    m_snake->hunger = -100;
  }

  Serial.println(String(m_snake->hunger));
  m_snake->hunger++;
}

