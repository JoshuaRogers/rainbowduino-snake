#ifndef __DISPLAY_H__
#define __DISPLAY_H__

#include <rainbowduino.h>
#include "color.h"
#include "coordinate.h"

class Display
{
public:
    Display(int ticks_per_redraw);
    void clear();
    void draw(int tick);
    void set_pixel(Coordinate coordinate, Color color);
    void tick();
    void prepare_buffer();
    
private:    
    int m_ticks_per_redraw;
    Color m_from_colors[4][4][4];
    Color m_to_colors[4][4][4];
};

#endif
