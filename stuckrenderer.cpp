#include "game.h"
#include "stuckrenderer.h"

void StuckRenderer::render(Game* game, Display* display)
{
    display->clear();
    for (int i = 0; i < game->snake.length(); i++) {
        display->set_pixel(game->snake.get_segment_position(i), get_segment_color(game, i));
    }
}

Color StuckRenderer::get_segment_color(Game* game, int i)
{
    int till_restart = abs(game->ticks);
    if (till_restart + i <= (game->snake.length() * 2) - 3) {
        return Color();
    } else if ((till_restart + i <= game->snake.length() * 2)) {
        return Color::from_hsv(0, 0, .5);
    }
    return Color(0, 0, 128);
}
