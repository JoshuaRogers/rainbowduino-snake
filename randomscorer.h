#ifndef __RANDOMSCORER_H__
#define __RANDOMSCORER_H__

#include "coordinate.h"
#include "movescorer.h"

class RandomScorer : public MoveScorer {
  double weigh(Coordinate coordinate);
};

#endif
