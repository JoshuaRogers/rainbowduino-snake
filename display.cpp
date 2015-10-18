#include <rainbowduino.h>
#include "color.h"
#include "display.h"

Display::Display(int ticks_per_redraw) : m_ticks_per_redraw(ticks_per_redraw)
{

}

void Display::draw(int tick)
{
    for (int z = 0; z <= 3; z++) {
        for (int x = 0; x <= 3; x++) {
            for (int y = 0; y <= 3; y++) {
                Color from = m_from_colors[z][x][y];
                Color to = m_to_colors[z][x][y];
                
                if (from != to) {
                    Color color = from.mix(to, ((float)tick + 1) / m_ticks_per_redraw);
                    Rb.setPixelZXY(z, x, y, color.to_uint32());
                }
            }
        }
    }
}

void Display::prepare_buffer()
{
    Color* target = &m_from_colors[0][0][0];
    for (Color* source = &m_to_colors[0][0][0]; source <= &m_to_colors[3][3][3]; source++)
    {
        *(target++) = *source;
    }
}

void Display::set_pixel(Coordinate coordinate, Color color)
{
    m_to_colors[coordinate.z][coordinate.x][coordinate.y] = color;
}
