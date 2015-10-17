#include <rainbowduino.h>
#include "game.h"
#include "restartrule.h"

RestartRule::RestartRule() : m_ticks_since_death(0)
{
    
}

void RestartRule::execute(Game* game)
{
    if (game->state == Game::Stuck) {
        m_ticks_since_death++;
        
        Serial.println("Restart in " + String(20 - m_ticks_since_death) + "ticks");
        
        if (m_ticks_since_death >= 20) {
            m_ticks_since_death = 0;
            game->state = Game::GameOver;
        }
    }
}