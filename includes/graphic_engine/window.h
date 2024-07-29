#ifndef WINDOW
    #define WINDOW

    #include "utils.h"

    #include <GL/freeglut.h>
    #include <iostream>

class Window
{
    private :
        STATUS status = STATUS::NOT_INITIALIZED;

        GLint display_mode = 0;

        GLint height = 0;
        GLint width = 0;
        std::string title = "";

    public :
        Window(void) {}
        Window(GLint height, GLint width, std::string title, GLint display_mode):
            height(height), width(width), title(title), status(STATUS::INITIALIZED), display_mode(display_mode)
            {start();}

        STATUS get_status(void) {return status;}
        GLfloat get_height(void) {return height;}
        GLfloat get_width(void) {return width;}

        void set_width(GLint width) {this->width = width;}
        void set_height(GLint height) {this->height = height;}

        void start(void);
};

#endif