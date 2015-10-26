#ifndef __WINRULE_H__
#define __WINRULE_H__

#include "gamerule.h"

class WinRule : public GameRule
{
public:
    void execute(Game* game);
};

#endif
