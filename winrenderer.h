#ifndef __WINRENDERER_H__
#define __WINRENDERER_H__

#include "renderer.h"

class WinRenderer : public Renderer
{
public:
    void render(Game* game, Display* display);
    
private:
    Color get_segment_color(Game* game, int i);
};

#endif