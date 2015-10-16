#ifndef __RANDOMSCORER_H__
#define __RANDOMSCORER_H__

#include "coordinate.h"
#include "movescorer.h"

class Game;

class RandomScorer : public MoveScorer
{
    double weigh(Game* game, Coordinate coordinate);
};

#endif
