#ifndef __WORLDRENDERER_H__
#define __WORLDRENDERER_H__

#include "world.h"

class Dot;
class Snake;

class WorldRenderer {
  public:
    WorldRenderer(World* world, Snake* snake, Dot* dot);
    void draw();

  private:
    World* m_world;

    // This really doesn't belong here. We need to change the concept of hunger to ripeness.
    Snake* m_snake;

    Dot* m_dot;

    uint32_t get_draw_color(World::Entity entity);
};

#endif
