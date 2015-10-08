#include "dot.h"
#include "dotrenderer.h"
#include "world.h"

DotRenderer::DotRenderer(Dot* dot, World* world) : m_dot(dot), m_world(world)
{
}

void DotRenderer::render(Display* display)
{
    if (m_world->is_valid(m_dot->position)) {
        display->set_pixel(m_dot->position, 0xFF9999);
    }
}

void DotRenderer::update()
{
    
}

