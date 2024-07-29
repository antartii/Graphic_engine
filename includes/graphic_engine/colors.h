#ifndef COLORS
    #define COLORS

#include <GL/freeglut.h>

class Color
{
    public :
        GLfloat r = 0;
        GLfloat g = 0;
        GLfloat b = 0;

        Color() {}
        Color(GLfloat red, GLfloat green, GLfloat blue): r(red), g(green), b(blue) {}

        static Color red() {return Color(1, 0, 0);}
        static Color green() {return Color(0, 1, 0);}
        static Color blue() {return Color(0, 0, 1);}
};

#endif