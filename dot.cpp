#include <rainbowduino.h>
#include "dot.h"

Dot::Dot() : m_is_spawned(false) {
  
}

bool Dot::is_spawned() {
  return m_is_spawned;
}

bool Dot::is_ripe() {
  return m_ticks_till_ripe == 0;
}

void Dot::clear() {
  m_is_spawned = false;
  position = Coordinate();
}

void Dot::spawn(Coordinate coordinate) {
  m_is_spawned = true;
  position = coordinate;
  m_ticks_till_ripe = random(100, 500);
}

void Dot::ripen() {
  if (m_ticks_till_ripe > 0)
  {
    m_ticks_till_ripe--;
  }
}

