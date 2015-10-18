#ifndef __SNAKE_H__
#define __SNAKE_H__

#define MAX_SNAKE_SIZE 64

#include "coordinate.h"

class World;

class Snake
{
public:
    Snake(World* world);
    void move(Coordinate head);
    void grow();
    int length();
    Coordinate get_segment_position(int segment);
    
private:
    World* m_world;
    Coordinate m_body_ring_buffer[MAX_SNAKE_SIZE];
    int m_ring_buffer_head;
    unsigned char m_body_size;
};

#endif
