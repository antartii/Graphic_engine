#include "game_manager.h"

void Game_manager::init(void)
{
    engine->set_window_title("retest");
    engine->set_window_size(Size(300, 300));
    engine->set_window_pos(Coordinates(0, 0));
    float thing[2] = {200, 500};
    test = Shapes_2D::create_ellipse(Ellipse(Coordinates(300, 300), thing));
    //Shapes_2D::delete_shape(0, Shapes_2D::CIRCLE);
}

void Game_manager::update(void)
{
    
}

void Game_manager::draw(void)
{
    //engine->draw(Coordinates(10, 10), Color::red()); // DRAW A POINT
    //Line::draw(Line(Coordinates(20, 20), Coordinates(100, 0)), Color::red()); // DRAW LINE
    //Triangle::draw(test, thing);// DRAW TRIANGLE
    //Quad::draw(Quad(Coordinates(0, 0), Coordinates(100, 0), Coordinates(100, 100), Coordinates(0, 100)), Color::red()); // DRAW SQUARE
    //Polygon::draw(Polygon(std::vector<Coordinates> {Coordinates(120, 120), Coordinates(70, 130), Coordinates(80, 140), Coordinates(20, 64), Coordinates(897, 65), Coordinates(45, 30), Coordinates(200, 100)}), Color::red()); // DRAW A POLYGON
    Shapes_2D::draw(*test, red);
}
