#ifndef __RENDERER_H__
#define __RENDERER_H__

#include "display.h"

class Game;

class Renderer
{
public:
    virtual void render(Game* game, Display* display) = 0;
};

#endif
