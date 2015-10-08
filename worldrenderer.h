#ifndef __WORLDRENDERER_H__
#define __WORLDRENDERER_H__

#include "renderer.h"
#include "world.h"

class Dot;
class Snake;

class WorldRenderer : public Renderer
{
public:
    WorldRenderer(World* world);
    void render(Display* display);
    void update();
    
private:
    World* m_world;
    int m_ticks;
};

#endif
