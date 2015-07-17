#include <rainbowduino.h>
#include "dot.h"
#include "world.h"

World::World(Dot* dot) : m_dot(dot) {
  for (Entity* entity = &m_entity[0][0][0]; entity <= &m_entity[3][3][3]; entity++)
  {
    *entity = Empty;
  }
}

World::Entity World::get_entity(Coordinate coordinate) {
  if (!is_valid(coordinate))
  {
    return Empty;
  }
  return m_entity[coordinate.z][coordinate.x][coordinate.y];
}

bool World::is_valid(Coordinate coordinate) {
  return coordinate.z < 4 && coordinate.x < 4 && coordinate.y < 4;
}

void World::set_entity(Coordinate coordinate, Entity entity) {
  if (!is_valid(coordinate))
  {
    return;
  }

  if (get_entity(coordinate) == Berry)
  {
    m_dot_coordinate = Coordinate();
  }

  if (entity == Berry)
  {
    m_dot_coordinate = coordinate;
  }
  
  m_entity[coordinate.z][coordinate.x][coordinate.y] = entity;
}

/**
 * Places a new dot on an unoccupied space.
 */
void World::place_dot() {
  Coordinate possible_dot;
  do
  {
    possible_dot.z = random(0, 4);
    possible_dot.x = random(0, 4);
    possible_dot.y = random(0, 4);
  } while(get_entity(possible_dot) != Empty);

  set_entity(possible_dot, Berry);
}

Coordinate World::get_dot_coordinate() {
  return m_dot_coordinate;
}

