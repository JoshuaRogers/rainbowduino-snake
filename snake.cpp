#include <rainbowduino.h>
#include "snake.h"
#include "world.h"

Snake::Snake(World* world) : m_world(world), m_body_size(2)
{
    for (int i = 0; i < MAX_SNAKE_SIZE; i++)
    {
        m_body_ring_buffer[i] = Coordinate(0, 0, 0);
    }
    
    m_world->set_entity(Coordinate(0, 0, 0), World::Snake);
}

void Snake::move(Coordinate head)
{
    if (!m_world->is_valid(head)) {
        Serial.println("Cannot move to invalid position");
        Serial.println("* " + String(head.z) + ", " + String(head.x) + ", " + String(head.y));
        return;
    }
    
    Serial.println("* " + String(head.z) + ", " + String(head.x) + ", " + String(head.y));
    
    m_ring_buffer_head = (m_ring_buffer_head + 1) % m_body_size;
    Coordinate tail = m_body_ring_buffer[m_ring_buffer_head];
    
    m_world->set_entity(tail, World::Empty);
    m_body_ring_buffer[m_ring_buffer_head] = head;
    m_world->set_entity(head, World::Snake);
}

void Snake::grow()
{
    if (m_body_size >= MAX_SNAKE_SIZE) {
        return;
    }
    
    for (int i = MAX_SNAKE_SIZE - 1; i > m_ring_buffer_head; i--) {
        m_body_ring_buffer[i] = m_body_ring_buffer[i - 1];
    }
    m_body_size++;
}

int Snake::length()
{
    return m_body_size;
}

Coordinate Snake::get_segment_position(int segment)
{
    int ring_buffer_position = (m_ring_buffer_head - segment + length()) % length();
    return m_body_ring_buffer[ring_buffer_position];
}

