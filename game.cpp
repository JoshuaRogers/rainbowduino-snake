#include "game.h"

Game::Game() : snake(Snake(&world)), state(Running), ticks(0)
{
    
}