#ifndef __HUNGERRULE_H__
#define __HUNGERRULE_H__

#include "movescorer.h"

class Dot;
class Snake;
class World;

class HungerScorer : public MoveScorer
{
public:
    HungerScorer(World* world, Snake* snake, Dot* dot);
    double weigh(Coordinate coordinate);
    
private:
    World* m_world;
    Snake* m_snake;
    Dot* m_dot;
};

#endif
