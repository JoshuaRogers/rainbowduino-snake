#include "game.h"
#include "runningrenderer.h"

void RunningRenderer::render(Game* game, Display* display)
{
    display->clear();
    render_dot(game, display);
    render_snake(game, display);
}

void RunningRenderer::render_snake(Game* game, Display* display) {
    for (int i = 0; i < game->snake.length(); i++) {
        display->set_pixel(game->snake.get_segment_position(i), get_segment_color(game, i));
    }
}

void RunningRenderer::render_dot(Game* game, Display* display) {
    if (!game->dot.is_spawned()) {
        return;
    }    

    int age = game->dot.get_age();
    display->set_pixel(game->dot.position, Color::from_hsv(((age * 60) % 360), min(age, 64) / 64.0, min(age, 80) / 80.0));
}

Color RunningRenderer::get_segment_color(Game* game, int i)
{
    int hue = ((game->ticks - i) * 4) % 360;
    return Color::from_hsv(hue, 1, .5);
}