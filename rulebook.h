#ifndef __RULEBOOK_H__
#define __RULEBOOK_H__

#define MAX_RULE_COUNT 10

class GameRule;

class RuleBook {
  public:
    bool add_rule(GameRule* gamerule);
    void execute();

  private:
    GameRule* m_rule_set[MAX_RULE_COUNT];
    int m_rule_count;
};

#endif
