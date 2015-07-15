#ifndef __DOTRULE_H__
#define __DOTRULE_H__

#include "gamerule.h"

class World;

class DotRule : public GameRule {
  public:
    DotRule(World* world);
    void execute();

  private:
    World* m_world;
};

#endif
