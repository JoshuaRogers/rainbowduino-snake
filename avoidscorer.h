#ifndef __AVOIDSCORER_H__
#define __AVOIDSCORER_H__

/**
 * During physical development, there was one connection that I could not make work.
 * This failed connection caused four LEDs to lack a red channel. Attempt to hide that.
 * It makes the snake's behaviour more unusual, but it should be less obvious.
 */

#include "coordinate.h"
#include "movescorer.h"

class Game;

class AvoidScorer : public MoveScorer
{
public:
    AvoidScorer();
    double weigh(Game* game, Coordinate coordinate);
    
private:
    Coordinate m_test_coordinates[4];
};

#endif /* avoidscorer_hpp */
