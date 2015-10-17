#include "dot.h"
#include "dotrenderer.h"
#include "game.h"
#include "world.h"

void DotRenderer::render(Game* game, Display* display)
{
    if (game->world->is_valid(game->dot->position)) {
        display->set_pixel(game->dot->position, 0xFF9999);
    }
}

void DotRenderer::update()
{
    
}

