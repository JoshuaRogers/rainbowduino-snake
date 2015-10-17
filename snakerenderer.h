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
    uint32_t get_color(int i);
    
    int m_color_head;
};

#endif
