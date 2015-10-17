#include <Rainbowduino.h>
#include "deathrule.h"
#include "display.h"
#include "dotdespawnrule.h"
#include "dotrenderer.h"
#include "dotripenrule.h"
#include "dotspawnrule.h"
#include "game.h"
#include "gamebuilder.h"
#include "gamerule.h"
#include "hungerscorer.h"
#include "linkedlist.h"
#include "moverule.h"
#include "node.h"
#include "randomscorer.h"
#include "renderer.h"
#include "restartrule.h"
#include "snakerenderer.h"
#include "straightscorer.h"
#include "worldrenderer.h"

#define TICKS_PER_REDRAW 12
#define FRAME_DELAY_MILLIS 20

Display *display;
GameBuilder game_builder;
Game* game;

LinkedList<Renderer*> renderers;
LinkedList<GameRule*> rule_book;

MoveRule* build_move_rule()
{
    MoveRule* move_rule = new MoveRule();
    move_rule->add_scorer(new HungerScorer());
    move_rule->add_scorer(new RandomScorer());
    move_rule->add_scorer(new StraightScorer());
    return move_rule;
}

void initialize_rules()
{
    rule_book.add(new DeathRule());
    rule_book.add(new DotDespawnRule());
    rule_book.add(new DotRipenRule());
    rule_book.add(new DotSpawnRule());
    rule_book.add(new RestartRule());
    rule_book.add(build_move_rule());
}

void initialize_renderers()
{
    renderers.add(new DotRenderer());
    renderers.add(new SnakeRenderer());
    renderers.add(new WorldRenderer());
}

/**
 * Arduino Initialization
 */
void setup() {
    Rb.init();
    Serial.begin(9600);

    game = game_builder.build();
    initialize_rules();
    initialize_renderers();
    display = new Display(TICKS_PER_REDRAW);
    Serial.println("Setup complete");
}

/**
 * Arduino Loop.
 */
void loop() {
    for (Node<GameRule*>* node = rule_book.get_head(); node != 0; node = node->next) {
      node->get_value()->execute(game);
    }

    display->prepare_buffer();
    for (Node<Renderer*>* node = renderers.get_head(); node != 0; node = node->next) {
      node->get_value()->update();
      node->get_value()->render(game, display);
    }
  
    for (int i = 0; i < TICKS_PER_REDRAW; i++) {
        uint32_t start = millis();
        display->draw(i);
        int32_t delay_time = FRAME_DELAY_MILLIS - (millis() - start);
        int32_t safe_delay_time = min(max(delay_time, 0), FRAME_DELAY_MILLIS);

        if (delay_time < 0) {
            Serial.println("Can't keep up!");
        }
    
        delay(safe_delay_time);
    }
    
    if (game->state == Game::GameOver) {
        Serial.println("Restarting.");
        delete game;
        game = game_builder.build();
    }
}

