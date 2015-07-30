#include "dot.h"
#include "dotdespawnrule.h"
#include "snake.h"

DotDespawnRule::DotDespawnRule(Snake* snake, Dot* dot) : m_snake(snake), m_dot(dot) {
  
}

void DotDespawnRule::execute() {
  if (m_dot->position == m_snake->get_head())
  {
    m_dot->clear();
    m_snake->grow();
  }
}
