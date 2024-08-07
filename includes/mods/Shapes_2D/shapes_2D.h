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

        enum TYPES{
            LINE = 0,
            TRIANGLE,
            QUAD,
            POLYGON,
            CIRCLE
        };

        static Line *create_line(Line line);
        static Quad *create_quad(Quad quad);
        static Triangle *create_triangle(Triangle triangle);
        static Polygon *create_polygon(Polygon polygon);
        static Circle *create_circle(Circle circle);
        static void delete_shape(unsigned int index, TYPES types);
        static void draw(Line line, Color color);
        static void draw(Triangle triangle, Color color);
        static void draw(Polygon polygon, Color color);
        static void draw(Quad quad, Color color);
        static void draw(Circle circle, Color color);

        static void compute_vp(void);

        // do function for deleting
        // send back an index instead of the address and do a get for address
};

#endif