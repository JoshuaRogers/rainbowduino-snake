#ifndef __RUNNINGRENDERER_H__
#define __RUNNINGRENDERER_H__

#include "renderer.h"

class RunningRenderer : public Renderer {
    void render(Game* game, Display* display);
    
private:
    void render_snake(Game* game, Display* display);
    void render_dot(Game* game, Display* display);
    Color get_segment_color(Game* game, int i);
};

#endif
