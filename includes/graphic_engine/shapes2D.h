#ifndef COORD2D
    #define COORD2D

    #include "utils.h"
    #include <iostream>

    #include <GL/freeglut.h>

enum class SHAPE_TYPE
{
    POINT = 0,
    LINE,
    TRIANGLE,
    QUAD,
    CIRCLE,
    COMPLEX
};

class Shapes2D {
    public :
        class Coord2D;
        class Quad;
};

class Shapes2D::Coord2D
{
    public :
        GLfloat x = 0;
        GLfloat y = 0;

        Coord2D() {}
        Coord2D(GLfloat x, GLfloat y): x(x), y(y)   {}

        SHAPE_TYPE shape_type(void) {return SHAPE_TYPE::POINT;}
};

class Shapes2D::Quad
{
    private :
        Coord2D start = Coord2D(0, 0);
        Coord2D end = Coord2D(0, 0);
        GLfloat width = 0;
        GLfloat height = 0;

    public :

        Quad() {}
        Quad(Coord2D start, Coord2D end);
        Quad(GLfloat width, GLfloat height):
            width(width), height(height), end(Coord2D(width, height)) {}
        Quad(Coord2D start, GLfloat width, GLfloat height):
            start(start), end(Coord2D(start.x + width, start.y + height)), width(width), height(height) {}
        
        Coord2D get_point(DIRECTION direction);
        SHAPE_TYPE shape_type(void) {return SHAPE_TYPE::QUAD;}
        GLboolean is_contained(Coord2D pos);
};

#endif