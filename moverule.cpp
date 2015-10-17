#include <rainbowduino.h>
#include "game.h"
#include "moverule.h"
#include "movescorer.h"
#include "node.h"
#include "snake.h"
#include "world.h"

void MoveRule::add_scorer(MoveScorer* scorer)
{
    m_scorers.add(scorer);
}

void MoveRule::execute(Game* game)
{
    if (game->state != Game::Running)
    {
        return;
    }
    
    Coordinate head = game->snake.get_segment_position(0);
    Coordinate candidates[6] = {
        Coordinate(head.z + 1, head.x, head.y),
        Coordinate(head.z - 1, head.x, head.y),
        Coordinate(head.z, head.x + 1, head.y),
        Coordinate(head.z, head.x - 1, head.y),
        Coordinate(head.z, head.x, head.y + 1),
        Coordinate(head.z, head.x, head.y - 1)
    };
    
    int best_candidate = 0;
    double move_weight[6];
    for (int i = 0; i < 6; i++) {
        // An arbitrarily large negative weight that should prevent an
        // invalid candidate from being the favored candidate.
        move_weight[i] = is_move_valid(game, candidates[i]) ? score(game, candidates[i]) : -1024;
        
        // We only care to find the highest weight choice.
        if (move_weight[i] >= move_weight[best_candidate]) {
            best_candidate = i;
        }
    }
    
    if (is_move_valid(game, candidates[best_candidate])) {
        game->snake.move(candidates[best_candidate]);
    }
}

bool MoveRule::is_move_valid(Game* game, Coordinate coordinate)
{
    return game->world.is_valid(coordinate) && game->world.get_entity(coordinate) != World::Snake;
}

double MoveRule::score(Game* game, Coordinate coordinate)
{
    int score = 0;
    for (Node<MoveScorer*>* node = m_scorers.get_head(); node != 0; node = node->next) {
        score += node->get_value()->weigh(game, coordinate);
    }
    
    return score;
}
