#ifndef ENGINE
#define ENGINE

#include "utils.h"
#include "window.h"
#include "shapes2D.h"
#include "colors.h"
#include "buttons.h"
#include "cppuat.h"

#include <GL/freeglut.h>
#include <iostream>
#include <map>
#include <algorithm>

class Engine
{
private:
    STATUS status = STATUS::NOT_INITIALIZED;

    GLint argc = 0;
    GLchar **argv = nullptr;
    GLchar **env = nullptr;

    Shapes2D::Coord2D mousepos = Shapes2D::Coord2D();

    Window *window = nullptr;

    std::vector<unsigned char> active_key;

    std::string objects_path = "assets/data/objects.uat";
    std::map<std::string, Button> buttons;

public:
    Engine(void) {}
    Engine(int argc, char **argv, char **env) : argc(argc), argv(argv), env(env), status(STATUS::INITIALIZED)
    {
        glutInit(&argc, argv);
    }

    // GETTER
    Window *get_window(void) { return window; }
    Shapes2D::Coord2D get_mousepos(void) { return mousepos; }
    Shapes2D::Coord2D get_mousepos_viewport(void) { return Shapes2D::Coord2D(screen_coord_to_viewport(mousepos.x, window->get_width()), screen_coord_to_viewport(mousepos.y, window->get_height())); }
    Button *get_button(std::string id) { return &(buttons[id]); }

    // SETTER
    void set_mousepos_viewport(Shapes2D::Coord2D new_mousepos) { mousepos = new_mousepos; }
    void set_objects_path(std::string objects_path) { this->objects_path = objects_path; }
    void set_main_functions(void (*display)(), void (*idle)(), void (*reshape)(int, int));
    void set_mouse_functions(void (*mouse)(int button, int state, int x, int y), void (*motion)(int x, int y), void (*passivemotion)(int x, int y));
    void set_keyboard_functions(void (*keyboard_pressed)(unsigned char key, int x, int y));
    void set_window(Window *window);

    // BASE FUNC
    void init();
    void start() { glutMainLoop(); };
    void update();
    void display();

    // DRAW
    void draw(Shapes2D::Coord2D pixel, Color color);
    void draw(Shapes2D::Quad quad, Color color);
    void draw_viewport(Shapes2D::Coord2D pixel, Color color);
    void draw_viewport(Shapes2D::Quad quad, Color color);

    // DATA
    void import_objects();

    // KEYBOARD
    void add_active_key(unsigned char key);
    void release_active_key(unsigned char key);
    GLboolean is_key_active(unsigned char key);
};

#endif