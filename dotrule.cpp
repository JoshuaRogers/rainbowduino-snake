#include <rainbowduino.h>
#include "dotrule.h"
#include "world.h"

DotRule::DotRule(World* world) : m_world(world) {
}

void DotRule::execute() {
  Coordinate dot_coordinate = m_world->get_dot_coordinate();
  if (!m_world->is_valid(dot_coordinate))
  {
    m_world->place_dot();
  }
}

