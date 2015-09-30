#include <Rainbowduino.h>
#include "display.h"
#include "dot.h"
#include "dotdespawnrule.h"
#include "dotrenderer.h"
#include "dotripenrule.h"
#include "dotspawnrule.h"
#include "edgescorer.h"
#include "gamerule.h"
#include "hungerscorer.h"
#include "linkedlist.h"
#include "moverule.h"
#include "node.h"
#include "randomscorer.h"
#include "renderer.h"
#include "snake.h"
#include "snakerenderer.h"
#include "world.h"
#include "worldrenderer.h"

#define TICKS_PER_REDRAW 15

Display *display;

Dot dot;
World world;
Snake snake(&world);

LinkedList<Renderer*> renderers;
LinkedList<GameRule*> rule_book;

MoveRule* build_move_rule()
{
  MoveRule* move_rule = new MoveRule(&world, &snake);
  move_rule->add_scorer(new EdgeScorer());
  move_rule->add_scorer(new HungerScorer(&world, &snake, &dot));
  move_rule->add_scorer(new RandomScorer());
  return move_rule;
}

void initialize_rules()
{
  rule_book.add(new DotDespawnRule(&snake, &dot));
  rule_book.add(new DotRipenRule(&dot));
  rule_book.add(new DotSpawnRule(&world, &snake, &dot));
  rule_book.add(build_move_rule());
}

void initialize_renderers()
{
  renderers.add(new DotRenderer(&dot, &world));
  renderers.add(new SnakeRenderer(&snake));
  renderers.add(new WorldRenderer(&world));
}

/**
 * Arduino Initialization
 */
void setup() {
  Rb.init();
  Serial.begin(9600);

  initialize_rules();
  initialize_renderers();
  display = new Display(TICKS_PER_REDRAW);
  Serial.println("Setup complete");
}

/**
 * Arduino Loop.
 */
void loop() {
  for (Node<GameRule*>* node = rule_book.get_head(); node != 0; node = node->next)
  {
    node->get_value()->execute();    
  }

  display->prepare_buffer();
  for (Node<Renderer*>* node = renderers.get_head(); node != 0; node = node->next)
  {
    node->get_value()->update();
    node->get_value()->render(display);
  }
  
  for (int i = 0; i < TICKS_PER_REDRAW; i++)
  {
    display->draw(i);
    delay(10);
  }
}
