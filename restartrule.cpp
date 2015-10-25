#include <rainbowduino.h>
#include "game.h"
#include "restartrule.h"

#define TIME_TILL_RESTART 36

RestartRule::RestartRule()
{
    
}

void RestartRule::execute(Game* game)
{
    if (game->state == Game::Stuck) {
        if (game->ticks > 0) {
            game->ticks = -TIME_TILL_RESTART;
        } else if (game->ticks == 0) {
            game->state = Game::GameOver;
        }
    }
}