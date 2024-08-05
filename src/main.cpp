
#include "engine.h"
#include "game_manager.h"

Engine engine;
Game_manager game_manager;

Engine* Engine::instance = nullptr; // set for the global variables

int main(int argc, char **argv, char **env)
{
    engine = Engine(&argc, argv);
    game_manager = Game_manager(&engine);

    Engine::set_instance(&engine); // set the global variables
    
    // DEFAULT VALUES
    engine.init("game window", Size(300, 300), Coordinates(0, 0));
    engine.set_game_manager(&game_manager);

    // STARTING
    game_manager.init();
    engine.start();
    return 0;
}