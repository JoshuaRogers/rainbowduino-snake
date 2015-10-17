#ifndef __DEATHRULE_H__
#define __DEATHRULE_H__

#include "coordinate.h"
#include "gamerule.h"

class DeathRule : public GameRule
{
public:
    void execute(Game* game);
    
private:
    Coordinate m_last_position;
};

#endif