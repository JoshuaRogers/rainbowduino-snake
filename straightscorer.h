#ifndef __EDGESCORER_H__
#define __EDGESCORER_H__

#include "coordinate.h"
#include "movescorer.h"

class Snake;

class StraightScorer : public MoveScorer
{
public:
    double weigh(Game* game, Coordinate coordinate);
};

#endif
