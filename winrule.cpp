#include "game.h"
#include "winrule.h"

void WinRule::execute(Game* game)
{
    if (game->snake.length() >= 20 && game->state == Game::Running) {
        game->state = Game::Win;
    }
}