#ifndef __SNAKE_H__
#define __SNAKE_H__

#define MAX_SNAKE_SIZE 7

#include "coordinate.h"

class World;

// QBert Terrance Bloodthirster

class Snake {
  public:
    Snake(World* world);
    Coordinate get_head();
    void move(Coordinate head);
    void grow();
  
  private:
    World* m_world;
    Coordinate m_body_ring_buffer[MAX_SNAKE_SIZE];
    unsigned char m_ring_buffer_head;
    unsigned char m_body_size;
};

#endif
