#include <rainbowduino.h>
#include "dot.h"

Dot::Dot()
{
    clear();
}

bool Dot::is_spawned()
{
    return m_age > 0;
}

bool Dot::is_ripe()
{
    return m_age > 100;
}

int Dot::get_age()
{
    return m_age;
}

void Dot::clear()
{
    position = Coordinate();
    m_age = 0;
}

void Dot::spawn(Coordinate coordinate)
{
    position = coordinate;
    m_age = 100;
}

void Dot::ripen()
{
    m_age++;
}

