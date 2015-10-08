#ifndef __MOVESCORER_H__
#define __MOVESCORER_H__

#include "coordinate.h"

class MoveScorer
{
public:
    /**
     * Weighs a coordinates favoriability.
     *
     * Returns: -100 to 100.
     */
    virtual double weigh(Coordinate coordinate) = 0;
};

#endif
