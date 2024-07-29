#include "engine.h"
#include "gamemanager.h"

#include <GL/freeglut.h>
#include <iostream>
#include <chrono>
#include <thread>

Engine engine;
GameManager gamemanager;
Window window;

void idle()
{
    gamemanager.update();
    engine.update();
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

void keyboard_pressed(unsigned char key, int x, int y)
{
    engine.add_active_key(key);
}

void keyboard_released(unsigned char key, int x, int y)
{
    engine.release_active_key(key);
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

    engine.set_window(&window);
    engine.set_main_functions(display, idle, reshape);
    engine.set_mouse_functions(mouse, motion, passive_motion);
    engine.set_keyboard_functions(keyboard_pressed);

    engine.init();
    gamemanager.init();
    engine.start();
    return 0;
}
