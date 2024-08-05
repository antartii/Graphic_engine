#ifndef GAME_MANAGER
#define GAME_MANAGER

#include "engine.h"

class Engine;

class Game_manager {
    private:
        Engine *engine;

    public:
        Game_manager() {};
        Game_manager(Engine *engine) : engine(engine) {};

        void init();
        void update();
        void draw();
};

#endif