#include "gamerule.h"
#include "rulebook.h"

bool RuleBook::add_rule(GameRule* gamerule) {
  if (m_rule_count >= MAX_RULE_COUNT)
  {
    return false;
  }
  
  m_rule_set[m_rule_count] = gamerule;
  m_rule_count++;
  return true;
}

void RuleBook::execute() {
  for (int i = 0; i < m_rule_count; i++)
  {
    m_rule_set[i]->execute();
  }
}

