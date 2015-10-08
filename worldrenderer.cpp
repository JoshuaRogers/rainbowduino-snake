#include "worldrenderer.h"

WorldRenderer::WorldRenderer(World* world) : m_world(world), m_ticks(0)
{
}

/**
 * Draws the grid based on the world map.
 */
void WorldRenderer::render(Display* display)
{
    for (int z = 0; z < 4; z++) {
        for (int x = 0; x < 4; x++) {
            for (int y = 0; y < 4; y++) {
                Coordinate coordinate = Coordinate(z, x, y);
                World::Entity entity = m_world->get_entity(coordinate);

                if (entity == World::Empty) {
                    // This gives a rather pleasing diagonal fade.
                    int id = m_ticks + z + x + y;
                    uint32_t color = id & 0x40 ? 0x010101 : 0x000000;
                    
                    if (id % 0x20 == 0) {
                        color = 0x111111;
                    }
                    display->set_pixel(coordinate, color);
                }
            }
        }
    }
}

void WorldRenderer::update()
{
    m_ticks++;
}

