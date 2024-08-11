
#include "engine.h"
#include "game_manager.h"

Engine engine;
Engine *Engine::instance = &engine;

// MODS GLOBAL VAR
Game_manager game_manager;
Game_manager *Game_manager::instance = &game_manager;

Shapes_2D shapes_2D;
Shapes_2D *Shapes_2D::instance = &shapes_2D;
// END MODS GLOBAL VAR

int main(int argc, char **argv, char **env)
{
    engine = Engine(&argc, argv);

    // MODS
    game_manager = Game_manager(&engine);
    engine.add_mod_update_function(Game_manager::update_callback);
    engine.add_mod_display_function(Game_manager::draw_callback);
    engine.add_mod_init_function(Game_manager::init_callback);
    engine.add_mod_reshape_function(Shapes_2D::compute_vp);
    // END MOD

    engine.start();
    return 0;
}