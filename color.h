#ifndef __COLOR_H__
#define __COLOR_H__

#include <rainbowduino.h>

class Color
{
public:
    static Color from_hsv(int h, double s, double v);
    
    Color();
    Color(unsigned char r, unsigned char g, unsigned char b);
    uint32_t to_uint32() const;
    Color mix(Color target, float amount);
    
    bool operator ==(const Color& color) const;
    bool operator !=(const Color& color) const;
    
    unsigned char r;
    unsigned char g;
    unsigned char b;
};

#endif