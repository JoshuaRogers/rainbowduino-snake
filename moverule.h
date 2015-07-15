#ifndef __MOVERULE_H__
#define __MOVERULE_H__

#include "coordinate.h"
#include "gamerule.h"

#define MAX_SCORERS 10

class MoveScorer;
class Snake;
class World;

class MoveRule : public GameRule {
  public:
    MoveRule(World* world, Snake* snake);
    bool add_scorer(MoveScorer* scorer);
    void execute();

  private:
    bool is_move_valid(Coordinate coordinate);
    double score(Coordinate coordinate);
  
    Snake* m_snake;
    World* m_world;
    MoveScorer* m_scorers[MAX_SCORERS];
    int m_scorer_count;
};

#endif
