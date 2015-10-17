#ifndef __GAMERULE_H__
#define __GAMERULE_H__

class Game;

class GameRule
{
public:
    virtual void execute(Game* game) = 0;
};

#endif
