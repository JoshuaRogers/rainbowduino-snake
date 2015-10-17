#ifndef __RESTARTRULE_H__
#define __RESTARTRULE_H__

#include "gamerule.h"

class RestartRule : public GameRule
{
public:
    RestartRule();
    void execute(Game* game);
    
private:
    int m_ticks_since_death;
};

#endif