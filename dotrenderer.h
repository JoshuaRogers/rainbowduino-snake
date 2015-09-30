#ifndef __DOTRENDERER_H__
#define __DOTRENDERER_H__

#include "renderer.h"

class Dot;
class World;

class DotRenderer : public Renderer {
  public:
    DotRenderer(Dot* dot, World* world);
    void render(Display* display);
    void update();

  protected:
    Dot* m_dot;
    World* m_world;
};

#endif
