#ifndef __DOTRENDERER_H__
#define __DOTRENDERER_H__

#include "renderer.h"

class DotRenderer : public Renderer
{
public:
    void render(Game* game, Display* display);
    void update();
};

#endif
