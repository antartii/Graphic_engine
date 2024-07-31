#include "gamemanager.h"
#include <GL/freeglut.h>

void test(void)
{
    std::cout << "clicked" << std::endl;
}

void test3(void)
{
    std::cout << "hovered" << std::endl;
}

void test2(void)
{
    std::cout << "unhovered" << std::endl;
}

void test1(void)
{
    std::cout << "unclicked" << std::endl;
}

void GameManager::init()
{
    engine->window->reshape(300, 300);
    Button *button_with_the_idea_la = engine->get_button("0");

    button_with_the_idea_la->set_visibility(true);
    button_with_the_idea_la->set_function(test, BUTTON_STATUS::CLICKED);
    button_with_the_idea_la->set_function(test3, BUTTON_STATUS::HOVERED);
    button_with_the_idea_la->set_function(test2, BUTTON_STATUS::UNHOVERED);
    button_with_the_idea_la->set_function(test1, BUTTON_STATUS::UNCLICKED);
}

void GameManager::update()
{

}
