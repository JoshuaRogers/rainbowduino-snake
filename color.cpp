#include "color.h"

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