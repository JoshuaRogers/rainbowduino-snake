#ifndef __SNAKERENDERER_H__
#define __SNAKERENDERER_H__

#include "renderer.h"

class SnakeRenderer : public Renderer
{
public:
    SnakeRenderer();
    void render(Game* game, Display* display);
    void update();
    
private:    
    int m_color_head;
    
    Color get_segment_color(Game* game, int i);
};

#endif
