#include <Rainbowduino.h>
#include "dot.h"
#include "dotdespawnrule.h"
#include "dotripenrule.h"
#include "dotspawnrule.h"
#include "edgescorer.h"
#include "gamerule.h"
#include "hungerscorer.h"
#include "linkedlist.h"
#include "moverule.h"
#include "node.h"
#include "randomscorer.h"
#include "snake.h"
#include "world.h"
#include "worldrenderer.h"

Dot dot;
World world;
Snake snake(&world);

WorldRenderer world_renderer(&world, &snake, &dot);
LinkedList<GameRule*> rule_book;

MoveRule* build_move_rule() {
  MoveRule* move_rule = new MoveRule(&world, &snake);
  move_rule->add_scorer(new EdgeScorer());
  move_rule->add_scorer(new HungerScorer(&world, &snake, &dot));
  move_rule->add_scorer(new RandomScorer());
  return move_rule;
}

/**
 * Arduino Initialization
 */
void setup() {
  Rb.init();

  rule_book.add(new DotDespawnRule(&snake, &dot));
  rule_book.add(new DotRipenRule(&dot));
  rule_book.add(new DotSpawnRule(&world, &snake, &dot));
  rule_book.add(build_move_rule());
}

/**
 * Arduino Loop.
 */
void loop() {
  for (Node<GameRule*>* node = rule_book.get_head(); node != 0; node = node->next)
  {
    node->get_value()->execute();    
  }
  world_renderer.draw();
  delay(100);
}

