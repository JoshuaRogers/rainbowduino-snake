#include "snake.h"
#include "world.h"

Snake::Snake(World* world) {
  m_world = world;
  m_body_ring_buffer[0] = Coordinate(0, 0, 0);
  m_body_ring_buffer[1] = Coordinate(0, 0, 1);
  m_body_ring_buffer[2] = Coordinate(0, 0, 2);
  m_body_ring_buffer[3] = Coordinate(0, 0, 3);
  m_body_ring_buffer[4] = Coordinate(0, 1, 3);
  m_world->set_entity(Coordinate(0, 0, 0), World::Snake);
  m_body_size = 5;
}

Coordinate Snake::get_head() {
  return m_body_ring_buffer[m_ring_buffer_head];
}

void Snake::move(Coordinate head) {
  if (!m_world->is_valid(head))
  {
    return;
  }
  
  m_ring_buffer_head = (m_ring_buffer_head + 1) % m_body_size;
  Coordinate tail = m_body_ring_buffer[m_ring_buffer_head];

  m_world->set_entity(tail, World::Empty);
  m_body_ring_buffer[m_ring_buffer_head] = head;
  m_world->set_entity(head, World::Snake);
}

