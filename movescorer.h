#ifndef __MOVESCORER_H__
#define __MOVESCORER_H__

#include "coordinate.h"

class Game;

class MoveScorer
{
public:
    /**
     * Weighs a coordinates favoriability.
     *
     * Returns: -100 to 100.
     */
    virtual double weigh(Game* game, Coordinate coordinate) = 0;
};

#endif
