#ifndef WINDOW
    #define WINDOW

    #include "utils.h"
    #include "shapes2D.h"

    #include <GL/freeglut.h>
    #include <iostream>

class Window
{
    private :
        STATUS status = STATUS::NOT_INITIALIZED;

        GLint display_mode = 0;
        GLboolean fullscreen = false;
        GLboolean resizing = false;

        GLint height = 300;
        GLint width = 300;
        GLint stored_height = 300;
        GLint stored_width = 300;

        Shapes2D::Coord2D position = Shapes2D::Coord2D(1, 1);
        std::string title = "";

    public :
        Window(void) {}
        Window(GLint height, GLint width, std::string title, GLint display_mode):
            height(height), width(width), title(title), status(STATUS::INITIALIZED), display_mode(display_mode)
            {start();}

        STATUS get_status(void) {return status;}
        GLfloat get_height(void) {return height;}
        GLfloat get_width(void) {return width;}
        
        GLboolean is_fullscreen(void) {return fullscreen;}
        GLboolean is_resizing(void) {return resizing;}

        void set_height(GLfloat height) {this->height = height;}
        void set_width(GLfloat width) {this->width = width;}

        void reshape(GLint width, GLint height);
        void toggle_fullscreen(void);

        void start(void);
};

#endif