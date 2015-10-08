#ifndef __DOTRIPENRULE_H__
#define __DOTRIPENRULE_H__

#include "gamerule.h"

class Dot;

class DotRipenRule : public GameRule
{
public:
    DotRipenRule(Dot* dot);
    void execute();
    
private:
    Dot* m_dot;
};

#endif