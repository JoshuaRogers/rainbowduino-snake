#include <Rainbowduino.h>
#include "dot.h"
#include "dotdespawnrule.h"
#include "dotripenrule.h"
#include "dotspawnrule.h"
#include "edgescorer.h"
#include "gamerule.h"
#include "hungerscorer.h"
#include "moverule.h"
#include "randomscorer.h"
#include "rulebook.h"
#include "snake.h"
#include "world.h"
#include "worldrenderer.h"

Dot dot;
World world;
Snake snake(&world);

WorldRenderer world_renderer(&world, &snake, &dot);
RuleBook rule_book;

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
  Serial.begin(9600);

  rule_book.add_rule(new DotDespawnRule(&snake, &dot));
  rule_book.add_rule(new DotRipenRule(&dot));
  rule_book.add_rule(new DotSpawnRule(&world, &snake, &dot));
  rule_book.add_rule(build_move_rule());
}

/**
 * Arduino Loop.
 */
void loop() {
  rule_book.execute();
  world_renderer.draw();
  delay(100);
}

