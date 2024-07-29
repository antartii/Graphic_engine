#include "gamemanager.h"

void GameManager::init()
{
    Button *button_with_the_idea_la = engine->get_button("0");

    button_with_the_idea_la->set_visibility(true);
}

void GameManager::update()
{
    Shapes2D::Coord2D mousepos = engine->get_mousepos();
    Button button = Button(Shapes2D::Quad(Shapes2D::Coord2D(0, 0), Shapes2D::Coord2D(50, 50)));

    button.update_state(mousepos, false);
}
