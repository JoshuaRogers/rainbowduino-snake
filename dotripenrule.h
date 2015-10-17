#ifndef __DOTRIPENRULE_H__
#define __DOTRIPENRULE_H__

#include "gamerule.h"

class DotRipenRule : public GameRule
{
public:
    void execute(Game* game);
};

#endif