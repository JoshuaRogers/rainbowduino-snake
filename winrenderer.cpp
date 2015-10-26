#include <rainbowduino.h>
#include "game.h"
#include "winrenderer.h"

void WinRenderer::render(Game* game, Display* display)
{
    display->clear();
    for (int i = 0; i < game->snake.length(); i++) {
        display->set_pixel(game->snake.get_segment_position(i), get_segment_color(game, i));
    }
}

Color WinRenderer::get_segment_color(Game* game, int i)
{
    return Color::from_hsv(abs((game->ticks + i) * 24) % 360, 1, .5);
}
