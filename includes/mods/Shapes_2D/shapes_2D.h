#ifndef SHAPES_2D
    #define SHAPES_2D

    #include "line.h"
    #include "triangle.h"
    #include "quad.h"
    #include "polygon.h"
    #include "circle.h"

    #include <vector>

class Shapes_2D
{
    private :
        std::vector<Line> lines;
        std::vector<Triangle> triangles;
        std::vector<Quad> quads;
        std::vector<Polygon> polygons;
        std::vector<Circle> circles;

        static Shapes_2D *instance;

    public :
        Shapes_2D() {};

        static Line *create_line(Line line);
        static Quad *create_quad(Quad quad);
        static Triangle *create_triangle(Triangle triangle);
        static Polygon *create_polygon(Polygon polygon);
        static Circle *create_circle(Circle circle);

        static void compute_vp(void);

        // do function for deleting
        // and also do on reshape
};

#endif