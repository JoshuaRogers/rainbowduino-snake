#ifndef __WORLDRENDERER_H__
#define __WORLDRENDERER_H__

#include "renderer.h"
#include "world.h"

class WorldRenderer : public Renderer
{
public:
    void render(Game* game, Display* display);
    void update();
};

#endif
