#ifndef __WORLD_H__
#define __WORLD_H__

#include "coordinate.h"

class World
{
public:
    enum Entity { Empty, Berry, Snake };
    
    World();
    Entity get_entity(Coordinate coordinate);
    bool is_valid(Coordinate coordinate);
    void set_entity(Coordinate coordinate, Entity entity);
    
private:
    World::Entity m_entity[4][4][4];
};

#endif
