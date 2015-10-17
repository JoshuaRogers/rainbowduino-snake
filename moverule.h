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
    void add_scorer(MoveScorer* scorer);
    void execute(Game* game);
    
private:
    bool is_move_valid(Game* game, Coordinate coordinate);
    double score(Game* game, Coordinate coordinate);

    LinkedList<MoveScorer*> m_scorers;
};
#endif
