#ifndef __GAME_H__
#define __GAME_H__

class Dot;
class Snake;
class World;

class Game
{
public:
    enum State { Running, Stuck, GameOver };
    
    Game(World* world, Snake* snake, Dot* dot);
    
    World* const world;
    Snake* const snake;
    Dot* const dot;
    State state;
};

#endif