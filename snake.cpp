#include <rainbowduino.h>
#include "snake.h"
#include "world.h"

Snake::Snake(World* world)
{
    m_world = world;
    m_body_ring_buffer[0] = Coordinate(0, 0, 0);
    m_world->set_entity(Coordinate(0, 0, 0), World::Snake);
    m_body_size = 2;
}

void Snake::move(Coordinate head)
{
    if (!m_world->is_valid(head)) {
        Serial.println("Cannot move to invalid position");
        return;
    }
    
    Coordinate old = get_segment_position(0);
    int oldx = old.x;
    int oldy = old.y;
    int oldz = old.z;
    int x = head.x;
    int y = head.y;
    int z = head.z;
    int dx = abs(oldx - x);
    int dy = abs(oldy - y);
    int dz = abs(oldz - z);
    
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

