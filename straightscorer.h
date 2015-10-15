#ifndef __EDGESCORER_H__
#define __EDGESCORER_H__

#include "coordinate.h"
#include "movescorer.h"

class Snake;

class StraightScorer : public MoveScorer
{
public:
    StraightScorer(Snake* snake);
    double weigh(Coordinate coordinate);
    
private:
    Snake* m_snake;
};

#endif
