#ifndef ENGINE
    #define ENGINE

    #include <GL/freeglut.h>
    #include <iostream>
    #include <vector>
    #include <map>
    #include <chrono>

    #include "system.h"
    #include "utils.h"

class Engine {
    private :
        int argc = 0;
        char **argv = nullptr;

        unsigned int display_plugine = GLUT_DOUBLE | GLUT_RGB;
        std::string window_title = "window";
        Size screen_size = Size(0, 0);
        Size window_size = Size(0, 0);
        Coordinates window_position = Coordinates(0, 0);
        int fps = 60;
        std::chrono::time_point<std::chrono::high_resolution_clock> timer_start = std::chrono::high_resolution_clock::now();
        float frame_duration = get_frame_duration(fps);
        Color background_color = Color(0, 0, 0);

        static Engine *instance;

        std::vector<void (*)()> plugin_init_functions;
        int plugin_init_functions_count = 0;
        std::vector<void (*)(int, int)> plugin_update_functions;
        int plugin_update_functions_count = 0;
        std::vector<void (*)()> plugin_display_functions;
        int plugin_display_functions_count = 0;
        std::vector<void (*)()> plugin_reshape_functions;
        int plugin_reshape_functions_count = 0;

    public :

        Engine() {};
        Engine(int *argc, char **argv);

        Size get_window_size(void) {return window_size;}
        Size get_screen_size(void) {return screen_size;}
        float get_timer(void) {
            std::chrono::time_point<std::chrono::high_resolution_clock> now = std::chrono::high_resolution_clock::now();
            std::chrono::duration<float> elapsed = now - timer_start;
            return elapsed.count();
        }
        void set_window_title(std::string title);
        void set_window_size(Size size);
        void set_window_pos(Coordinates pos);
        void set_background(Color color);
        void toggle_fullscreen() {glutFullScreen();}

        void init();
        void start();
        void update(int fps, int value);
        void display();
        void reshape(int w, int h);
        void draw(Coordinates point, Color color);

        void add_plugin_update_function(void (*plugin_update_function)(int, int));
        void add_plugin_display_function(void (*plugin_display_function)());
        void add_plugin_init_function(void (*add_init_function)());
        void add_plugin_reshape_function(void (*add_reshape_function)());

        static void set_instance(Engine *engine) {instance = engine;};
        static int get_fps() {return instance->fps;}
        static Coordinates coordinates_to_vp(Coordinates point);

        static Size get_window_size_callback() {return instance->get_window_size();}
        static void update_callback(int value) {instance->update(Engine::get_fps(), value);}
        static void display_callback() {instance->display();}
        static void reshape_callback(int w, int h) {instance->reshape(w, h);}
};

#endif