#ifndef __RESTARTRULE_H__
#define __RESTARTRULE_H__

#include "gamerule.h"

class RestartRule : public GameRule
{
public:
    void execute(Game* game);
};

#endif