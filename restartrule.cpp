#include <rainbowduino.h>
#include "game.h"
#include "restartrule.h"

#define TIME_TILL_RESTART 20

RestartRule::RestartRule() : m_ticks_since_death(0)
{
    
}

void RestartRule::execute(Game* game)
{
    if (game->state == Game::Stuck) {
        m_ticks_since_death++;
        
        Serial.println("Restart in " + String(TIME_TILL_RESTART - m_ticks_since_death) + "ticks");
        
        if (m_ticks_since_death >= TIME_TILL_RESTART) {
            m_ticks_since_death = 0;
            game->state = Game::GameOver;
        }
    }
}