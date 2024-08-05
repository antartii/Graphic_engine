#ifndef ENGINE
    #define ENGINE

    #include <GL/freeglut.h>
    #include <iostream>
    #include <vector>
    #include <thread>
    #include <chrono>

    #include "utils.h"

class Game_manager;

class Engine {
    private :
        int argc = 0;
        char **argv = nullptr;
        unsigned int display_mode = GLUT_DOUBLE | GLUT_RGB;
        std::string window_title = "window";
        Size window_size;
        Coordinates window_position;
        int fps = 60;

        static Engine *instance;

        // MODS
        std::vector<void (*)(int, int)> mod_update_functions;
        int mod_update_functions_count = 0;
        std::vector<void (*)()> mod_display_functions;
        int mod_display_functions_count = 0;

    public :
        Engine() {};
        Engine(int *argc, char **argv);

        void add_mod_update_function(void (*mod_update_function)(int, int));
        void add_mod_display_function(void (*mod_display_function)());
        Size get_window_size(void) {return window_size;}

        void init(std::string title, Size size, Coordinates position);
        void start();
        void update(int fps, int value);
        void display();
        void reshape(int w, int h);

        void draw(Coordinates point, Color color);
        void draw(Line line, Color color);
        void draw(Triangle triangle, Color color);
        void draw(Quad quad, Color color);

        static Coordinates Coordinates_to_vp(Coordinates point);
        static Line line_to_vp(Line line);
        static Triangle triangle_to_vp(Triangle triangle);
        static Quad quad_to_vp(Quad quad);

        static void set_instance(Engine *engine) {instance = engine;};
        static Size get_window_size_callback() {return instance->get_window_size();}
        static int get_fps() {return instance->fps;}

        static void update_callback(int value) {instance->update(Engine::get_fps(), value);}
        static void display_callback() {instance->display();}
        static void reshape_callback(int w, int h) {instance->reshape(w, h);}
};

#endif