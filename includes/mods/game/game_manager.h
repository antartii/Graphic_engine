#ifndef GAME_MANAGER
#define GAME_MANAGER


#include <iostream>
#include <cstdlib>

#include "engine.h"
#include "shapes_2D.h"

// Chat includes
#include "user.h"
#include "chat_message.h"
#include "server.h"

class Engine;

class Game_manager {
    private:
        static Game_manager *instance;
        Engine *engine;

        // GAME CODE STARTING HERE
        unsigned int current_streamer;
        unsigned int test;

        Server server;
        // GAME CODE ENDING HERE

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