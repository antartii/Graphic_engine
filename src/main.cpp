
#include "engine.h"
#include "game_manager.h"

Engine engine;
Engine *Engine::instance = nullptr;

// MODS GLOBAL VAR
Game_manager game_manager;
Game_manager *Game_manager::instance = nullptr;
// END MODS GLOBAL VAR

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
    // END MOD

    engine.start();
    return 0;
}