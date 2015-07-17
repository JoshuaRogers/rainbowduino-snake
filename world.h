#ifndef __WORLD_H__
#define __WORLD_H__

#include "coordinate.h"

class Dot;

class World {
  public:
    enum Entity { Empty, Berry, Snake };
  
    World(Dot* dot);
    Entity get_entity(Coordinate coordinate);
    bool is_valid(Coordinate coordinate);
    void set_entity(Coordinate coordinate, Entity entity);
    void place_dot();
    Coordinate get_dot_coordinate();

  private:
    Dot* m_dot;
    World::Entity m_entity[4][4][4];
    Coordinate m_dot_coordinate;
};

#endif
