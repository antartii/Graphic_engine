#include "game_manager.h"

void Game_manager::init(void)
{
    engine->set_window_title("retest");
    engine->set_window_size(Size(300, 300));
    engine->set_window_pos(Coordinates(0, 0));
}

void Game_manager::update(void)
{
    
}

void Game_manager::draw(void)
{
    /*
    engine->draw(Coordinates(10, 10), Color::red()); // DRAW A POINT
    engine->draw(Line(Coordinates(20, 20), Coordinates(100, 0)), Color::red()); // DRAW LINE
    engine->draw(Triangle(Coordinates(20, 20), Coordinates(120, 20), Coordinates(60, 120)), Color::red());// DRAW TRIANGLE
    engine->draw(Quad(Coordinates(50, 0), Coordinates(100, 50), Coordinates(50, 100), Coordinates(0, 50)), Color::red()); // DRAW SQUARE
    */
   engine->draw(Polygon(std::vector<Coordinates> {Coordinates(120, 120), Coordinates(70, 130), Coordinates(80, 140), Coordinates(20, 64), Coordinates(897, 65), Coordinates(45, 30), Coordinates(200, 100)}), Color::red()); // DRAW A POLYGON
   //engine->draw(Circle(Coordinates(50, 50), 300, 100), Color::red());
}
