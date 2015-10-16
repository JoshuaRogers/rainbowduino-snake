#ifndef __MOVERULE_H__
#define __MOVERULE_H__

#include "coordinate.h"
#include "gamerule.h"
#include "linkedlist.h"

class Game;
class MoveScorer;

class MoveRule : public GameRule
{
public:
    MoveRule(Game* game);
    void add_scorer(MoveScorer* scorer);
    void execute();
    
private:
    bool is_move_valid(Coordinate coordinate);
    double score(Coordinate coordinate);
    
    Game* m_game;
    LinkedList<MoveScorer*> m_scorers;
};
#endif
