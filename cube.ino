#include <Rainbowduino.h>

// Game Objects
#include "game.h"
#include "gamebuilder.h"
#include "linkedlist.h"
#include "node.h"

// Game Rules
#include "gamerule.h"
#include "deathrule.h"
#include "moverule.h"
#include "restartrule.h"
#include "winrule.h"
#include "dotripenrule.h"
#include "dotspawnrule.h"
#include "dotdespawnrule.h"

// Snake Behaviors
#include "avoidscorer.h"
#include "hungerscorer.h"
#include "randomscorer.h"
#include "straightscorer.h"

// Graphics
#include "display.h"
#include "renderer.h"
#include "runningrenderer.h"
#include "stuckrenderer.h"
#include "winrenderer.h"

#define TICKS_PER_REDRAW 10
#define FRAME_DELAY_MILLIS 20

Display *display;
GameBuilder game_builder;
Game* game;

Renderer* renderers[Game::STATE_COUNT];
LinkedList<GameRule*> rule_book;

MoveRule* build_move_rule()
{
    MoveRule* move_rule = new MoveRule();
    move_rule->add_scorer(new AvoidScorer());
    move_rule->add_scorer(new HungerScorer());
    move_rule->add_scorer(new RandomScorer());
    move_rule->add_scorer(new StraightScorer());
    return move_rule;
}

void initialize_rules()
{
    rule_book.add(new RestartRule());
    rule_book.add(new DeathRule());
    rule_book.add(new WinRule());
    rule_book.add(new DotDespawnRule());
    rule_book.add(new DotRipenRule());
    rule_book.add(new DotSpawnRule());
    rule_book.add(build_move_rule());
}

void initialize_renderers()
{
    renderers[Game::GameOver] = NULL;
    renderers[Game::Running] = new RunningRenderer();
    renderers[Game::Stuck] = new StuckRenderer();
    renderers[Game::Win] = new WinRenderer();
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
    Renderer* state_renderer = renderers[game->state];
    if (state_renderer != NULL) {
        state_renderer->render(game, display);
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
    
    game->ticks++;
}

