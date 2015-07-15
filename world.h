#ifndef __WORLD_H__
#define __WORLD_H__

#include "coordinate.h"

class World {
  public:
    enum Entity { Empty, Dot, Snake };
  
    World();
    Entity get_entity(Coordinate coordinate);
    bool is_valid(Coordinate coordinate);
    void set_entity(Coordinate coordinate, Entity entity);
    void place_dot();
    Coordinate get_dot_coordinate();

  private:
    World::Entity m_entity[4][4][4];
    Coordinate m_dot_coordinate;
};

#endif
