#ifndef __HUNGERRULE_H__
#define __HUNGERRULE_H__

#include "movescorer.h"

class Game;

class HungerScorer : public MoveScorer
{
public:
    double weigh(Game* game, Coordinate coordinate);
};

#endif
