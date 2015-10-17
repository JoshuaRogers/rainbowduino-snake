#include "dot.h"
#include "dotdespawnrule.h"
#include "game.h"
#include "snake.h"

void DotDespawnRule::execute(Game* game)
{
    if (game->dot.position == game->snake.get_segment_position(0)) {
        game->dot.clear();
        game->snake.grow();
    }
}
