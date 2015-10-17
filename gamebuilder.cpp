#include "dot.h"
#include "game.h"
#include "gamebuilder.h"
#include "snake.h"
#include "world.h"

Game* GameBuilder::build()
{
    Game* game = new Game();
    return game;
}