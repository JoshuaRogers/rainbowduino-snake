#ifndef __HUNGERRULE_H__
#define __HUNGERRULE_H__

#include "movescorer.h"

class Snake;
class World;

class HungerScorer : public MoveScorer {
  public:
    HungerScorer(World* world, Snake* snake);
    double weigh(Coordinate coordinate);

  private:
    World* m_world;
    Snake* m_snake;
};

#endif
