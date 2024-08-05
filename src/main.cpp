
#include "engine.h"
#include "game_manager.h"

// GLOBAL
Engine engine;
Engine *Engine::instance = nullptr;

// MODS GLOBAL
Game_manager game_manager;
Game_manager *Game_manager::instance = nullptr;

int main(int argc, char **argv, char **env)
{
    engine = Engine(&argc, argv);
    Engine::set_instance(&engine);

    // MODS
    game_manager = Game_manager(&engine);
    Game_manager::set_instance(&game_manager);
    engine.add_mod_update_function(Game_manager::update_callback);
    engine.add_mod_display_function(Game_manager::draw_callback);
    engine.add_mod_init_function(Game_manager::init_callback);

    // STARTING
    engine.start();
    return 0;
}