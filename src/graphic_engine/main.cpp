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
    engine.window->set_height(height);
    engine.window->set_width(width);

    glViewport(0, 0, width, height);
}


void keyboard_pressed(unsigned char key, int x, int y)
{

}

void keyboard_released(unsigned char key, int x, int y)
{
    engine.release_active_key(key);
}

void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN)
            engine.add_active_key(SPECIAL_KEYS::MOUSE_LEFT_BUTTON);
        else
            engine.release_active_key(SPECIAL_KEYS::MOUSE_LEFT_BUTTON);
    } else if (button == GLUT_RIGHT_BUTTON) {
        if (state == GLUT_DOWN)
            engine.add_active_key(SPECIAL_KEYS::MOUSE_RIGHT_BUTTON);
        else
            engine.release_active_key(SPECIAL_KEYS::MOUSE_RIGHT_BUTTON);
    }
}

void mouse_entry(int state)
{
    if (state == GLUT_LEFT)
        engine.set_mouse_in_window(false);
    else if (state == GLUT_ENTERED)
        engine.set_mouse_in_window(true);
}

void motion(int x, int y)
{
    engine.set_mousepos_viewport(Shapes2D::Coord2D(x, engine.window->get_height() - y));
}

void passive_motion(int x, int y)
{

}

int main(int argc, char **argv, char **env)
{
    engine = Engine(argc, argv, env);
    gamemanager = GameManager(&engine);
    window = Window(0, 0, "test", GLUT_DOUBLE | GLUT_RGB);

    engine.window = &window;
    engine.set_main_functions(display, idle, reshape);
    engine.set_mouse_functions(mouse, motion, passive_motion, mouse_entry);
    engine.set_keyboard_functions(keyboard_pressed, keyboard_released);

    engine.init();
    gamemanager.init();
    engine.start();
    return 0;
}
