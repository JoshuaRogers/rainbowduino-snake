#include "game.h"
#include "snakerenderer.h"
#include "snake.h"

unsigned char RED[64] = {255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 247, 223, 199, 175, 151, 127, 103, 79, 55, 31, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 31, 55, 79, 103, 127, 151, 175, 199, 223, 247, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255};
unsigned char GREEN[64] = {0, 23, 47, 71, 95, 119, 143, 167, 191, 215, 239, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 254, 231, 207, 183, 159, 135, 111, 87, 63, 39, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
unsigned char BLUE[64] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 15, 39, 63, 87, 111, 135, 159, 183, 207, 231, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 239, 215, 191, 167, 143, 119, 95, 71, 47, 23};

SnakeRenderer::SnakeRenderer() : m_color_head(0)
{
}

void SnakeRenderer::render(Game* game, Display* display)
{
    for (int i = 0; i < game->snake->length(); i++) {
        display->set_pixel(game->snake->get_segment_position(i), get_color(m_color_head));
    }
}

void SnakeRenderer::update()
{
    m_color_head = (m_color_head + 1) % 64;
}

uint32_t SnakeRenderer::get_color(int i)
{
    return ((uint32_t)RED[i] << 16) +
           ((uint32_t)GREEN[i] << 8) +
           BLUE[i];
}

