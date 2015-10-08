#include <rainbowduino.h>
#include "coordinate.h"
#include "dot.h"
#include "dotspawnrule.h"
#include "snake.h"
#include "world.h"

DotSpawnRule::DotSpawnRule(World* world, Snake* snake, Dot* dot) : m_world(world), m_snake(snake), m_dot(dot), m_spawn_delay(50)
{
}

void DotSpawnRule::execute()
{
    if (m_dot->is_spawned()) {
        return;
    }
    
    if (m_spawn_delay == 0) {
        m_spawn_delay = random(256, 1024);
        m_spawn_delay = 50;
        place_dot();
    }
    
    m_spawn_delay--;
}

/**
 * Places a new dot on an unoccupied space.
 */
void DotSpawnRule::place_dot()
{
    Coordinate possible_dot;
    do {
        possible_dot.z = random(0, 4);
        possible_dot.x = random(0, 4);
        possible_dot.y = random(0, 4);
    } while(m_world->get_entity(possible_dot) != World::Empty);
    
    m_dot->spawn(possible_dot);
    m_world->set_entity(possible_dot, World::Berry);
}
