#include <rainbowduino.h>
#include "snake.h"
#include "world.h"

Snake::Snake(World* world) : m_world(world), m_ring_buffer_head(0), m_body_size(2)
{
    move(Coordinate(0, 0, 0));
}

void Snake::move(Coordinate head)
{
    if (!m_world->is_valid(head)) {
        Serial.println("Cannot move to invalid position");
        return;
    }
    
    m_ring_buffer_head = (m_ring_buffer_head <= 0 ? MAX_SNAKE_SIZE : m_ring_buffer_head) - 1;
    m_body_ring_buffer[m_ring_buffer_head] = head;
    
    m_world->set_entity(get_segment_position(m_body_size), World::Empty);
    m_world->set_entity(get_segment_position(0), World::Snake);
}

void Snake::grow()
{
    if (m_body_size < MAX_SNAKE_SIZE) {
        m_body_size++;
    }
}

int Snake::length()
{
    return m_body_size;
}

Coordinate Snake::get_segment_position(int segment)
{
    int ring_buffer_position = (m_ring_buffer_head + segment) % MAX_SNAKE_SIZE;
    return m_body_ring_buffer[ring_buffer_position];
}

