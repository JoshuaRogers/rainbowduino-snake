#include "dot.h"
#include "game.h"
#include "gamebuilder.h"
#include "snake.h"
#include "world.h"

Game* GameBuilder::build()
{
    Dot* dot = new Dot();
    World* world = new World();
    Snake* snake = new Snake(world);

    Game* game = new Game(world, snake, dot);
    return game;
}