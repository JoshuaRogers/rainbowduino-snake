#include <rainbowduino.h>
#include "game.h"
#include "straightscorer.h"
#include "snake.h"

#define LIKES_WEIGHT 25
#define DISLIKES_WEIGHT -25

double StraightScorer::weigh(Game* game, Coordinate coordinate)
{
    Coordinate head = game->snake->get_segment_position(0);
    Coordinate neck = game->snake->get_segment_position(1);
    Coordinate forward = Coordinate(head.z + (head.z - neck.z), head.x + (head.x - neck.x), head.y + (head.y - neck.y));
    
    return forward == coordinate ? LIKES_WEIGHT : DISLIKES_WEIGHT;
}
