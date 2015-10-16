/**
 * Provides enough entropy to allow otherwise equally weighted options
 * to be selected, rather than falling back on the ordering of options.
 */

#include <rainbowduino.h>
#include "game.h"
#include "randomscorer.h"

double RandomScorer::weigh(Game* game, Coordinate coordinate)
{
  return random(0, 11) - 6;
}
