#ifndef __DOTSPAWNRULE_H__
#define __DOTSPAWNRULE_H__

#include "gamerule.h"

class Dot;
class Snake;
class World;

class DotSpawnRule : public GameRule {
  public:
    DotSpawnRule(World* world, Snake* snake, Dot* dot);
    void execute();

  private:
    void place_dot();
  
    World* m_world;
    Snake* m_snake;
    Dot* m_dot;

    unsigned int m_spawn_delay;
};

#endif
