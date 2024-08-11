#ifndef GAME_MANAGER
#define GAME_MANAGER

#include "engine.h"
#include "shapes_2D.h"

#include <iostream>

class Engine;

class Game_manager {
    private:
        static Game_manager *instance;
        Engine *engine;

        // TEST
        Drawable *test;
        Color red = Color(1, 0, 0);
        // END OF TEST

    public:
        Game_manager() {};
        Game_manager(Engine *engine) : engine(engine) {};

        void init();
        void update();
        void draw();

        static void set_instance(Game_manager *game_manager) {instance = game_manager;}
        static void init_callback() {instance->init();}
        static void update_callback(int, int) {instance->update();}
        static void draw_callback() {instance->draw();}
};

#endif