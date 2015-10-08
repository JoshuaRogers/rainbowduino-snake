#include <rainbowduino.h>
#include "dot.h"
#include "world.h"

World::World()
{
    for (Entity* entity = &m_entity[0][0][0]; entity <= &m_entity[3][3][3]; entity++) {
        *entity = Empty;
    }
}

World::Entity World::get_entity(Coordinate coordinate)
{
    if (!is_valid(coordinate)) {
        return Empty;
    }
    return m_entity[coordinate.z][coordinate.x][coordinate.y];
}

bool World::is_valid(Coordinate coordinate)
{
    return coordinate.z < 4 && coordinate.x < 4 && coordinate.y < 4;
}

void World::set_entity(Coordinate coordinate, Entity entity)
{
    if (!is_valid(coordinate)) {
        return;
    }
    
    m_entity[coordinate.z][coordinate.x][coordinate.y] = entity;
}

