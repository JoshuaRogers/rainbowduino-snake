#ifndef __SNAKERENDERER_H__
#define __SNAKERENDERER_H__

#include "renderer.h"

class Snake;

class SnakeRenderer : public Renderer {
  public:
    SnakeRenderer(Snake* snake);
    void render(Display* display);
    void update();
    
  private:
    uint32_t get_color(int i);
  
    Snake* m_snake;
    int m_color_head;
};

#endif
