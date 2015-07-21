#include <rainbowduino.h>
#include "worldrenderer.h"
#include "snake.h"

unsigned char RED[64] = {255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 247, 223, 199, 175, 151, 127, 103, 79, 55, 31, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 31, 55, 79, 103, 127, 151, 175, 199, 223, 247, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255};
unsigned char GREEN[64] = {0, 23, 47, 71, 95, 119, 143, 167, 191, 215, 239, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 254, 231, 207, 183, 159, 135, 111, 87, 63, 39, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
unsigned char BLUE[64] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 15, 39, 63, 87, 111, 135, 159, 183, 207, 231, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 239, 215, 191, 167, 143, 119, 95, 71, 47, 23};

int color = 0;

WorldRenderer::WorldRenderer(World* world, Snake* snake) {
  m_world = world;
  m_snake = snake;
}

/**
 * Draws the grid based on the world map.
 */
void WorldRenderer::draw() {
  color = (color + 1) % 64;
  for (int z = 0; z < 4; z++)
  {
    for (int x = 0; x < 4; x++)
    {
      for (int y = 0; y < 4; y++)
      {
        World::Entity entity = m_world->get_entity(Coordinate(z, x, y));
        Rb.setPixelZXY(z, x, y, get_draw_color(entity));
      }
    }
  }
}

/**
 * Calculates the draw color for a given entity.
 */
uint32_t WorldRenderer::get_draw_color(World::Entity entity) {
  if (entity == World::Snake)
  {
            uint32_t c = RED[color];
    c = c << 8;
    c += GREEN[color];
    c = c << 8;
    c += BLUE[color];
    return c;
  }
  else if (entity == World::Berry)
  {
    uint32_t red = 100 + m_snake->hunger;
    uint32_t green = 100 - m_snake->hunger;
    return (red << 16) + (green << 8) + red;
//    return 0xFFFFFF;
  }
  else if (entity == World::Empty)
  {
    return 0x111111;
  }
  return 0x008888;
}

