#ifndef __DISPLAY_H__
#define __DISPLAY_H__

#include <rainbowduino.h>
#include "coordinate.h"

class Display
{
public:
    Display(int ticks_per_redraw);
    void draw(int tick);
    void set_pixel(Coordinate coordinate, uint32_t color);
    void tick();
    void prepare_buffer();
    
private:
    uint32_t mix_color(uint32_t from, uint32_t to, int tick);
    uint32_t mix_component(uint32_t from, uint32_t to, int tick, int bit_shift);
    uint32_t inline mask_component(uint32_t color, int bit_shift);
    
    int m_ticks_per_redraw;
    uint32_t m_from_colors[4][4][4];
    uint32_t m_to_colors[4][4][4];
};

#endif
