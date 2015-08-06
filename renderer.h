#ifndef __RENDERER_H__
#define __RENDERER_H__

#include "display.h"

class Renderer {
  public:
    virtual void render(Display* display) = 0;
};

#endif
