#ifndef __GAME_H__
#define __GAME_H__

#include "dot.h"
#include "snake.h"
#include "world.h"

class Game
{
public:
    enum State { GameOver = 0, Running = 1, Stuck = 2, STATE_COUNT = 3 };
    
    Game();
    
    World world;
    Snake snake;
    Dot dot;
    State state;
    
    int ticks;
};

#endif