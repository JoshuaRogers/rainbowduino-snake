#include <rainbowduino.h>
#include "color.h"

Color Color::from_hsv(int h, double s, double v)
{
    double h1 = h / 60.0;
    int h2 = floor(h1);
    
    double f = h1 - h2;
    
    double v1 = 255 * v;
    double pv = v1 * (1 - s);
    double qv = v1 * (1 - s * f);
    double tv = v1 * (1 - s * (1 - f));
    
    if (h2 == 0) { return Color(v1, tv, pv); }
    if (h2 == 1) { return Color(qv, v1, pv); }
    if (h2 == 2) { return Color(pv, v1, tv); }
    if (h2 == 3) { return Color(pv, qv, v1); }
    if (h2 == 4) { return Color(tv, pv, v1); }
    if (h2 == 5) { return Color(v1, pv, qv); }
    return Color();
}

Color::Color() : r(0), g(0), b(0)
{
    
}

Color::Color(unsigned char r, unsigned char g, unsigned char b) : r(r), g(g), b(b)
{
    
}

uint32_t Color::to_uint32() const
{
    return ((uint32_t)r << 16) +
           ((uint32_t)g << 8) +
                      b;
}

Color Color::mix(Color target, float amount)
{
    float secondary_amount = amount > 1.0 ? 1.0 : amount;
    float primary_amount = 1.0 - secondary_amount;
    
    return Color((r * primary_amount) + (target.r * secondary_amount),
                 (g * primary_amount) + (target.g * secondary_amount),
                 (b * primary_amount) + (target.b * secondary_amount));
}

bool Color::operator ==(const Color& color) const
{
    return to_uint32() == color.to_uint32();
}

bool Color::operator !=(const Color& color) const
{
    return !operator==(color);
}