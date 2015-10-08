#ifndef __EDGESCORER_H__
#define __EDGESCORER_H__

#include "coordinate.h"
#include "movescorer.h"

class EdgeScorer : public MoveScorer
{
public:
    double weigh(Coordinate coordinate);
    
private:
    bool is_edge(unsigned char point);
};

#endif
