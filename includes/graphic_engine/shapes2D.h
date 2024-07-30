#ifndef COORD2D
    #define COORD2D

    #include "utils.h"

    #include <iostream>
    #include <GL/freeglut.h>
    #include <map>
    #include <vector>

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
        class Line;
        class Quad;

        static Shapes2D::Coord2D point_to_viewport(Shapes2D::Coord2D point, Coord2D window_resolution);
        static GLboolean is_contained(std::vector<Shapes2D::Line> shape_lines, Shapes2D::Coord2D point);
};

class Shapes2D::Coord2D
{
    public :
        GLfloat x = 0;
        GLfloat y = 0;

        Coord2D() {}
        Coord2D(GLfloat x, GLfloat y): x(x), y(y)   {}

        SHAPE_TYPE shape_type(void) {return SHAPE_TYPE::POINT;}

        static std::map<std::string, Shapes2D::Coord2D> extract_from_table(std::vector<std::vector<std::string>> table);
};

class Shapes2D::Line {
    public :
        Coord2D points[2] = {Coord2D(0, 0), Coord2D(0, 0)};

        Line(){}
        Line(Coord2D points[2]) { for (int i = 0; i < 2; i += 1) this->points[i] = points[i];}

        SHAPE_TYPE shape_type(void) {return SHAPE_TYPE::LINE;}
};

class Shapes2D::Quad {
    public :
        Coord2D points[4] = {Coord2D(0,0), Coord2D(0,0), Coord2D(0,0), Coord2D(0,0)};

        Quad() {}
        Quad(Coord2D points[4]) {for (int i = 0; i < 4; i += 1) this->points[i] = points[i];};

        SHAPE_TYPE shape_type(void) {return SHAPE_TYPE::QUAD;}
        std::vector<Line> get_lines(void);
};

#endif