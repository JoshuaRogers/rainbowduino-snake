#include "worldrenderer.h"

WorldRenderer::WorldRenderer(World* world) : m_world(world), m_ticks(0) {

}

/**
 * Draws the grid based on the world map.
 */
void WorldRenderer::render(Display* display) {
  for (int z = 0; z < 4; z++)
  {
    for (int x = 0; x < 4; x++)
    {
      for (int y = 0; y < 4; y++)
      {
        Coordinate coordinate = Coordinate(z, x, y);
        World::Entity entity = m_world->get_entity(coordinate);
        if (entity == World::Empty)
        {
          display->set_pixel(coordinate, m_ticks < 100 ? 0x000000 : 0x111111);
        }
      }
    }
  }
}

void WorldRenderer::update() {
  m_ticks++;
}
