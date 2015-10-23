#include "avoidscorer.h"
#include "game.h"

AvoidScorer::AvoidScorer()
{
    m_test_coordinates[0] = Coordinate(2, 3, 2);
    m_test_coordinates[1] = Coordinate(2, 2, 3);
    m_test_coordinates[2] = Coordinate(2, 1, 2);
    m_test_coordinates[3] = Coordinate(2, 0, 3);
}

double AvoidScorer::weigh(Game* game, Coordinate coordinate)
{
    for (int i = 0; i < 4; i++) {
        if (coordinate == m_test_coordinates[i]) {
            return -5;
        }
    }
    
    return 0;
}