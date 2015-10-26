#ifndef __STUCKRENDERER_H__
#define __STUCKRENDERER_H__

#include "renderer.h"

class Game;

class StuckRenderer : public Renderer
{
public:
    void render(Game* game, Display* display);
    
private:
    Color get_segment_color(Game* game, int i);
};

#endif
