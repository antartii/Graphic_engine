#ifndef ENGINE
    #define ENGINE

    #include <GL/freeglut.h>
    #include <iostream>
    #include <vector>

    #include "utils.h"
    #include "shapes_2D.h"

class Game_manager;

class Engine {
    private :
        int argc = 0;
        char **argv = nullptr;
        unsigned int display_mode = GLUT_DOUBLE | GLUT_RGB;
        std::string window_title = "window";
        Size window_size = Size(300, 300);
        Coordinates window_position = Coordinates(0, 0);
        int fps = 60;

        static Engine *instance;

        // MODS
        std::vector<void (*)()> mod_init_functions;
        int mod_init_functions_count = 0;
        std::vector<void (*)(int, int)> mod_update_functions;
        int mod_update_functions_count = 0;
        std::vector<void (*)()> mod_display_functions;
        int mod_display_functions_count = 0;

    public :
        Engine() {};
        Engine(int *argc, char **argv);

        // MODS
        void add_mod_update_function(void (*mod_update_function)(int, int));
        void add_mod_display_function(void (*mod_display_function)());
        void add_mod_init_function(void (*add_init_display_function)());

        Size get_window_size(void) {return window_size;}
        void set_window_title(std::string title) {window_title = title;}
        void set_window_size(Size size) {window_size = size;}
        void set_window_pos(Coordinates pos) {window_position = pos;}

        void init();
        void start();
        void update(int fps, int value);
        void display();
        void reshape(int w, int h);

        static void set_instance(Engine *engine) {instance = engine;};
        static Size get_window_size_callback() {return instance->get_window_size();}
        static int get_fps() {return instance->fps;}

        static void update_callback(int value) {instance->update(Engine::get_fps(), value);}
        static void display_callback() {instance->display();}
        static void reshape_callback(int w, int h) {instance->reshape(w, h);}
};

#endif