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
        int hue = (m_color_head - (i * 4) + 360) % 360;
        display->set_pixel(game->snake.get_segment_position(i), Color::from_hsv(hue, 1, 1));
    }
}

void SnakeRenderer::update()
{
    m_color_head = (m_color_head + 4) % 360;
}
