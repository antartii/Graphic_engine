#ifndef SHAPES_2D
    #define SHAPES_2D

    #include "utils.h"
    #include "GL/freeglut.h"

class Shapes2D {
    private:

    public:
        class Line;
        class Triangle;
        class Quad;
        class Polygon;

        static void draw(Line line, Color color, Size window);
        static void draw(Triangle triangle, Color color, Size window);
        static void draw(Quad quad, Color color, Size window);
        static void draw(Polygon polygon, Color color, Size window);

        static Line line_to_vp(Line line, Size window);
        static Triangle triangle_to_vp(Triangle triangle, Size window);
        static Quad quad_to_vp(Quad quad, Size window);
        static Polygon polygon_to_vp(Polygon polygon, Size window);
};

class Shapes2D::Line {
    public :
        Coordinates p1, p2;

        Line(){}
        Line(Coordinates p1, Coordinates p2): p1(p1), p2(p2) {};
};

class Shapes2D::Triangle {
    public :
        Coordinates p1, p2, p3;

        Triangle() {};
        Triangle(Coordinates p1, Coordinates p2, Coordinates p3): p1(p1), p2(p2), p3(p3) {};
};

class Shapes2D::Quad {
    public :
        Coordinates p1, p2, p3, p4;

        Quad() {};
        Quad(Coordinates p1, Coordinates p2, Coordinates p3, Coordinates p4): p1(p1), p2(p2), p3(p3), p4(p4){};
};

class Shapes2D::Polygon {
    public :
        std::vector<Coordinates> points;

        Polygon() {};
        Polygon(std::vector<Coordinates> points): points(points) {}
};

#endif