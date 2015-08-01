#ifndef __GAMERULE_H__
#define __GAMERULE_H__

#include "snake.h"
#include "world.h"

class GameRule {
  public:
    virtual void execute() = 0;
};

#endif
