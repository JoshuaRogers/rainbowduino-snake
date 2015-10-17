#ifndef __DOTEATENRULE_H__
#define __DOTEATENRULE_H__

#include "gamerule.h"

class DotDespawnRule : public GameRule
{
public:
    void execute(Game* game);
};

#endif