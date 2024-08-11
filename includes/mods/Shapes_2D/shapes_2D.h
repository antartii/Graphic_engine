#ifndef SHAPES_2D
    #define SHAPES_2D

    #include "drawable.h"

    #include <vector>

class Shapes_2D
{
    private :
        std::vector<Line> lines;
        std::vector<Triangle> triangles;
        std::vector<Quad> quads;
        std::vector<Polygon> polygons;
        std::vector<Circle> circles;
        std::vector<Ellipse> ellipses;
        std::vector<Bezier_curve> bezier_curves;
        std::vector<Drawable> drawables;

        static Shapes_2D *instance;

    public :
        Shapes_2D() {};

        enum TYPES{
            LINE = 0,
            TRIANGLE,
            QUAD,
            POLYGON,
            CIRCLE,
            ELLIPSE,
            BEZIER_CURVES,
            DRAWABLE
        };

        enum DRAW_MODE {
            OUTLINE = 0,
            FILL
        };

        static Line *create_line(Line line);
        static Quad *create_quad(Quad quad);
        static Triangle *create_triangle(Triangle triangle);
        static Polygon *create_polygon(Polygon polygon);
        static Circle *create_circle(Circle circle);
        static Ellipse *create_ellipse(Ellipse ellipse);
        static Bezier_curve *create_bezier_curve(Bezier_curve bezier_curve);
        static Drawable *create_drawable(Drawable drawable);
        static void delete_shape(unsigned int index, TYPES types);
        static void draw(Line line, Color color);
        static void draw(Triangle triangle, Color color, DRAW_MODE mode);
        static void draw(Polygon polygon, Color color, DRAW_MODE mode);
        static void draw(Quad quad, Color color, DRAW_MODE mode);
        static void draw(Circle circle, Color color, DRAW_MODE mode);
        static void draw(Ellipse Ellipse, Color color, DRAW_MODE mode);
        static void draw(Bezier_curve bezier_curve, Color color, DRAW_MODE mode);
        static void draw(Drawable drawable, Color color, DRAW_MODE mode);

        static void compute_vp(void);

        // do function for deleting
        // send back an index instead of the address and do a get for address
};

#endif