#include <rainbowduino.h>
#include "straightscorer.h"
#include "snake.h"

#define LIKES_WEIGHT 25
#define DISLIKES_WEIGHT -25

StraightScorer::StraightScorer(Snake* snake) : m_snake(snake)
{
}

double StraightScorer::weigh(Coordinate coordinate)
{
    Coordinate head = m_snake->get_segment_position(0);
    Coordinate neck = m_snake->get_segment_position(1);
    Coordinate forward = Coordinate(head.z + (head.z - neck.z), head.x + (head.x - neck.x), head.y + (head.y - neck.y));
    
    if (forward.z == 5 || forward.x == 5 || forward.y == 5)
    {
        Serial.println("IMPOSSIBLE STATE");
        Serial.println(" Head: " + String(head.z) + ", " + String(head.x) + ", " + String(head.y));
        Serial.println(" Body: " + String(neck.z) + ", " + String(neck.x) + ", " + String(neck.y));
    }
    
    return forward == coordinate ? LIKES_WEIGHT : DISLIKES_WEIGHT;
}
