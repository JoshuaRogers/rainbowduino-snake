#include "dot.h"
#include "dotripenrule.h"
#include "game.h"

void DotRipenRule::execute(Game* game)
{
    if (game->dot.is_spawned()) {
        game->dot.ripen();
    }
}
