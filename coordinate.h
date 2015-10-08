#ifndef __COORDINATE_H__
#define __COORDINATE_H__

class Coordinate
{
public:
    Coordinate();
    Coordinate(unsigned char _z, unsigned char _x, unsigned char _y);
    
    bool operator ==(const Coordinate& coord) const;
    bool operator !=(const Coordinate& coord) const;
    
    unsigned char z;
    unsigned char x;
    unsigned char y;
};

#endif
