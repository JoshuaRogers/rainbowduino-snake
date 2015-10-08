#include "dot.h"
#include "dotripenrule.h"

DotRipenRule::DotRipenRule(Dot* dot) : m_dot(dot)
{
}

void DotRipenRule::execute()
{
    if (m_dot->is_spawned()) {
        m_dot->ripen();
    }
}
