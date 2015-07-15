#ifndef __HUNGERRULE_H__
#define __HUNGERFULE_H__

#include "gamerule.h"

class Snake;
class World;

class HungerRule : public GameRule {
  public:
    HungerRule(World* world, Snake* snake);
    void execute();

  private:
    Snake* m_snake;
    World* m_world;

    Coordinate m_dot_last_seen;
};

#endif
