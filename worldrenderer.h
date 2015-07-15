#ifndef __WORLDRENDERER_H__
#define __WORLDRENDERER_H__

#include "world.h"

// Does not belong.
class Snake;

class WorldRenderer {
  public:
    WorldRenderer(World* world, Snake* snake);
    void draw();

  private:
    World* m_world;

    // This really doesn't belong here. We need to change the concept of hunger to ripeness.
    Snake* m_snake;

    uint32_t get_draw_color(World::Entity entity);
};

#endif
