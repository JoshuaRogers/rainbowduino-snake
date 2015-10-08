#include <rainbowduino.h>
#include "display.h"

Display::Display(int ticks_per_redraw) : m_ticks_per_redraw(ticks_per_redraw)
{
    for (uint32_t* i = &m_from_colors[0][0][0]; i < &m_from_colors[3][3][3]; i++) {
        *i = 0;
    }
    
    for (uint32_t* i = &m_to_colors[0][0][0]; i < &m_to_colors[3][3][3]; i++) {
        *i = 0;
    }
}

void Display::draw(int tick)
{
    for (int z = 0; z <= 3; z++) {
        for (int x = 0; x <= 3; x++) {
            for (int y = 0; y <= 3; y++) {
                uint32_t from = m_from_colors[z][x][y];
                uint32_t to = m_to_colors[z][x][y];
                
                if (from != to) {
                    Rb.setPixelZXY(z, x, y, mix_color(from, to, tick));
                }
            }
        }
    }
}

void Display::prepare_buffer()
{
    uint32_t* target = &m_from_colors[0][0][0];
    for (uint32_t* source = &m_to_colors[0][0][0]; source <= &m_to_colors[3][3][3]; source++)
    {
        *(target++) = *source;
    }
}

void Display::set_pixel(Coordinate coordinate, uint32_t color)
{
    m_to_colors[coordinate.z][coordinate.x][coordinate.y] = color;
}

uint32_t Display::mix_color(uint32_t from, uint32_t to, int tick)
{
    return mix_component(from, to, tick, 16) +
           mix_component(from, to, tick, 8) +
           mix_component(from, to, tick, 0);
}

uint32_t Display::mix_component(uint32_t from, uint32_t to, int tick, int bit_shift)
{
    float to_phase = (tick + 1) / (float)m_ticks_per_redraw;
    float from_phase = 1 - to_phase;
    uint32_t color1 = mask_component(from, bit_shift) * from_phase;
    uint32_t color2 = mask_component(to, bit_shift) * to_phase;
    return mask_component(color1 + color2, bit_shift);
}

uint32_t inline Display::mask_component(uint32_t color, int bit_shift)
{
    return ((color >> bit_shift) & 0x0000FF) << bit_shift;
}

