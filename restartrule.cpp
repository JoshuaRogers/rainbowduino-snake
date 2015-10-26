#include <rainbowduino.h>
#include "game.h"
#include "restartrule.h"

RestartRule::RestartRule()
{
    
}

void RestartRule::execute(Game* game)
{
    if (game->state == Game::Stuck) {
        if (game->ticks > 0) {
            // This is a bit arbitrary really. Just trying to ensure any death animation has sufficient time to play.
            game->ticks = (-2 * game->snake.length());
        } else if (game->ticks == 0) {
            game->state = Game::GameOver;
        }
    }
}