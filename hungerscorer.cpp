#include <rainbowduino.h>
#include "dot.h"
#include "game.h"
#include "hungerscorer.h"
#include "snake.h"
#include "world.h"

double HungerScorer::weigh(Game* game, Coordinate coordinate)
{
    if (!game->world->is_valid(game->dot->position)) {
        return 0;
    }
    
    if (!game->dot->is_ripe()) {
        // If the candidate is the dot, but we are still full, avoid it.
        // Otherwise, we don't care.
        return coordinate == game->dot->position ? -100 : 0;
    }
    
    Coordinate head = game->snake->get_segment_position(0);
    
    int snake_distance = abs(head.z - game->dot->position.z) +
                         abs(head.x - game->dot->position.x) +
                         abs(head.y - game->dot->position.y);
    int candidate_distance = abs(coordinate.z - game->dot->position.z) +
                             abs(coordinate.x - game->dot->position.x) +
                             abs(coordinate.y - game->dot->position.y);
    int weight = game->dot->get_age() - 100;
    return candidate_distance < snake_distance ? weight : -weight;
}

