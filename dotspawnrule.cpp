#include <rainbowduino.h>
#include "coordinate.h"
#include "dot.h"
#include "dotspawnrule.h"
#include "game.h"
#include "snake.h"
#include "world.h"

DotSpawnRule::DotSpawnRule() : m_spawn_delay(50)
{
}

void DotSpawnRule::execute(Game* game)
{
    if (game->dot->is_spawned()) {
        return;
    }
    
    if (m_spawn_delay == 0) {
        m_spawn_delay = random(256, 1024);
        m_spawn_delay = 50;
        place_dot(game);
    }
    
    m_spawn_delay--;
}

/**
 * Places a new dot on an unoccupied space.
 */
void DotSpawnRule::place_dot(Game* game)
{
    Coordinate possible_dot;
    do {
        possible_dot.z = random(0, 4);
        possible_dot.x = random(0, 4);
        possible_dot.y = random(0, 4);
    } while(game->world->get_entity(possible_dot) != World::Empty);
    
    game->dot->spawn(possible_dot);
    game->world->set_entity(possible_dot, World::Berry);
}
