#include "engine.h"
#include "gamemanager.h"

#include <GL/freeglut.h>
#include <iostream>
#include <chrono>
#include <thread>

Engine engine;
GameManager gamemanager;
Window window;

void setup()
{
    engine.set_objects_path("assets/data/objects.uat");
    engine.import_objects();
}

void idle()
{
    gamemanager.update();
    glutPostRedisplay();
    std::this_thread::sleep_for(std::chrono::nanoseconds(1));
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    
    engine.display();
    glutSwapBuffers();
}

void reshape(GLint width, GLint height)
{
    engine.get_window()->set_width(width);
    engine.get_window()->set_height(height);

    glViewport(0, 0, width, height);
}

void mouse(int button, int state, int x, int y)
{
    
}

void motion(int x, int y)
{
    engine.set_mousepos_viewport(Shapes2D::Coord2D(x, engine.get_window()->get_height() - y));
}

void passive_motion(int x, int y)
{

}

int main(int argc, char **argv, char **env)
{
    engine = Engine(argc, argv, env);
    gamemanager = GameManager(&engine);
    window = Window(300, 300, "test", GLUT_DOUBLE | GLUT_RGB);

    engine.add_window(&window);
    engine.set_main_functions(display, idle, reshape);
    engine.set_mouse_functions(mouse, motion, passive_motion);

    setup();
    gamemanager.init();
    engine.start();
    return 0;
}

// TODO
/*

Draw relative to another object

*/