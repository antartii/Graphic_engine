
#include "engine.h"
#include "game_manager.h"

Engine engine;
Game_manager game_manager;

Engine *Engine::instance = nullptr;
Game_manager *Game_manager::instance = nullptr;

int main(int argc, char **argv, char **env)
{
    engine = Engine(&argc, argv);
    game_manager = Game_manager(&engine);

    // SET GLOBAL VARIABLE
    Game_manager::set_instance(&game_manager);
    Engine::set_instance(&engine);
    
    // DEFAULT VALUES
    engine.init("game window", Size(300, 300), Coordinates(0, 0));

    engine.add_mod_update_function(Game_manager::update_callback);
    engine.add_mod_display_function(Game_manager::draw_callback);
    // STARTING
    game_manager.init();
    engine.start();
    return 0;
}