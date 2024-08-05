#include "game_manager.h"

void Game_manager::init(void)
{
    engine->init("retest", Size(300, 300), Coordinates(0, 0));
}

void Game_manager::update(void)
{
    
}

void Game_manager::draw(void)
{
    engine->draw(Coordinates(10, 10));
}
