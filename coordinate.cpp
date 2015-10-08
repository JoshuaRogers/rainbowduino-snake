#include "coordinate.h"

/**
 * Unless proper coordinates are given, Coordinates are initialized to an invalid value.
 */
Coordinate::Coordinate() : z(255), x(255), y(255)
{
}

Coordinate::Coordinate(unsigned char _z, unsigned char _x, unsigned char _y) : z(_z), x(_x), y(_y)
{
}

bool Coordinate::operator==(const Coordinate& coord) const
{
    return z == coord.z && x == coord.x && y == coord.y;
}

bool Coordinate::operator!=(const Coordinate& coord) const
{
    return !operator==(coord);
}

