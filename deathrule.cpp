#include <rainbowduino.h>
#include "deathrule.h"
#include "game.h"
#include "snake.h"

void DeathRule::execute(Game* game)
{
    Coordinate current_position = game->snake->get_segment_position(0);
    
    if (current_position == m_last_position && game->state == Game::Running) {
        game->state = Game::Stuck;
        Serial.println("Snake is stuck");
    }
    
    m_last_position = current_position;
}