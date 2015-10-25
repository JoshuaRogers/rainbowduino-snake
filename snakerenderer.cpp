#include "color.h"
#include "game.h"
#include "snakerenderer.h"
#include "snake.h"

SnakeRenderer::SnakeRenderer() : m_color_head(0)
{
}

void SnakeRenderer::render(Game* game, Display* display)
{
    for (int i = 0; i < game->snake.length(); i++) {
        display->set_pixel(game->snake.get_segment_position(i), get_segment_color(game, i));
    }
}

void SnakeRenderer::update()
{
    m_color_head = (m_color_head + 4) % 360;
}

Color SnakeRenderer::get_segment_color(Game* game, int i)
{
    if (game->state == Game::Running) {
        int hue = (m_color_head - (i * 4) + 360) % 360;
        return Color::from_hsv(hue, 1, 1);
    }
    
    int till_restart = abs(game->ticks);
    if (till_restart + i <= 20) {
        return Color();
    } else if ((till_restart + i <= 24)) {
        return Color(255, 255, 255);
    }
    return Color::from_hsv(250, 1 - (i * .05), 1);
}
