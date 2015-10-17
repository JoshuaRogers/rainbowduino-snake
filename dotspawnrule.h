#ifndef __DOTSPAWNRULE_H__
#define __DOTSPAWNRULE_H__

#include "gamerule.h"

class DotSpawnRule : public GameRule
{
public:
    DotSpawnRule();
    void execute(Game* game);
    
private:
    void place_dot(Game* game);
    
    unsigned int m_spawn_delay;
};

#endif
