#ifndef __GAME_H__
#define __GAME_H__

#include "dot.h"
#include "snake.h"
#include "world.h"

class Game
{
public:
    enum State { Running, Stuck, GameOver };
    
    Game();
    
    World world;
    Snake snake;
    Dot dot;
    State state;
};

#endif