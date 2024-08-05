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
    /*
    engine->draw(Coordinates(10, 10), Color::red()); // DRAW A POINT
    engine->draw(Line(Coordinates(20, 20), Coordinates(100, 0)), Color::red()); // DRAW LINE
    */
   engine->draw(Triangle(Coordinates(20, 20), Coordinates(120, 20), Coordinates(60, 120)), Color::red());// DRAW TRIANGLE
}
