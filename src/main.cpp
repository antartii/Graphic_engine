
#include "engine.h"
#include "game_manager.h"
#include "text.h"

Engine engine;
Engine *Engine::instance = &engine;

// PLUGINS GLOBAL VAR
Game_manager game_manager;
Game_manager *Game_manager::instance = &game_manager;

Shapes_2D shapes_2D;
Shapes_2D *Shapes_2D::instance = &shapes_2D;

Text_storage text_storage;
Text_storage *Text_storage::instance = &text_storage;
// END PLUGINS GLOBAL VAR

int main(int argc, char **argv, char **env)
{
    engine = Engine(&argc, argv);

    // PLUGINS
    game_manager = Game_manager(&engine);
    engine.add_plugin_update_function(Game_manager::update_callback);
    engine.add_plugin_display_function(Game_manager::draw_callback);
    engine.add_plugin_init_function(Game_manager::init_callback);
    engine.add_plugin_reshape_function(Shapes_2D::compute_vp);
    engine.add_plugin_reshape_function(Text_storage::update_vp);
    // END PLUGIN

    engine.start();
    return 0;
}