#ifndef __DOTEATENRULE_H__
#define __DOTEATENRULE_H__

#include "gamerule.h"

class Dot;
class Snake;

class DotDespawnRule : public GameRule
{
public:
    DotDespawnRule(Snake* snake, Dot* dot);
    void execute();
    
private:
    Snake* m_snake;
    Dot* m_dot;
};

#endif