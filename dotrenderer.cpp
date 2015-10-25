#include <rainbowduino.h>
#include "dot.h"
#include "dotrenderer.h"
#include "game.h"
#include "world.h"

void DotRenderer::render(Game* game, Display* display)
{
    if (!game->dot.is_spawned()) {
        return;
    }

    int age = game->dot.get_age();
    display->set_pixel(game->dot.position, Color::from_hsv(((age * 60) % 360), min(age, 64) / 64.0, min(age, 80) / 80.0));
}

void DotRenderer::update()
{
    
}

