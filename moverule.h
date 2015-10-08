#ifndef __MOVERULE_H__
#define __MOVERULE_H__

#include "coordinate.h"
#include "gamerule.h"
#include "linkedlist.h"

class MoveScorer;
class Snake;
class World;

class MoveRule : public GameRule
{
public:
    MoveRule(World* world, Snake* snake);
    void add_scorer(MoveScorer* scorer);
    void execute();
    
private:
    bool is_move_valid(Coordinate coordinate);
    double score(Coordinate coordinate);
    
    Snake* m_snake;
    World* m_world;
    LinkedList<MoveScorer*> m_scorers;
};
#endif
