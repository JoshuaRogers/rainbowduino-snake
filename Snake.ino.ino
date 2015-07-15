#include <Rainbowduino.h>
#include "dotrule.h"
#include "edgescorer.h"
#include "gamerule.h"
#include "hungerrule.h"
#include "hungerscorer.h"
#include "moverule.h"
#include "randomscorer.h"
#include "rulebook.h"
#include "snake.h"
#include "world.h"
#include "worldrenderer.h"

World world;
Snake snake(&world);

WorldRenderer world_renderer(&world, &snake);
RuleBook rule_book;

/**
 * Arduino Initialization
 */
void setup() {
  Rb.init();
  world.place_dot();

  MoveRule* move_rule = new MoveRule(&world, &snake);
  move_rule->add_scorer(new HungerScorer(&world, &snake));
  move_rule->add_scorer(new RandomScorer());
  move_rule->add_scorer(new EdgeScorer());

  rule_book.add_rule(new HungerRule(&world, &snake));
  rule_book.add_rule(new DotRule(&world));
  rule_book.add_rule(move_rule);
}

/**
 * Arduino Loop.
 */
void loop() {
  rule_book.execute();
  world_renderer.draw();
  delay(100);
}

