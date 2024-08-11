#ifndef SHAPES_2D_DRAWABLE
#define SHAPES_2D_DRAWABLE

#include "utils.h"
#include "engine.h"
#include "line.h"
#include "triangle.h"
#include "quad.h"
#include "polygon.h"
#include "circle.h"
#include "ellipse.h"
#include "bezier_curves.h"

class Drawable {
    private :
        std::vector<Coordinates> points;
        std::vector<Coordinates> vp_points;
        int points_count = 0;

    public :
        Drawable(){};

        void add(Coordinates new_point);
        void add(std::vector<Coordinates> new_points);
        void add(Line new_line);
        void add(Triangle new_triangle);
        void add(Quad new_quad);
        void add(Polygon new_polygon);
        void add(Circle new_circle);
        void add(Ellipse new_ellipse);
        void add(Bezier_curve new_bezier_curve);

        int get_points_count(void) {return points_count;}
        Coordinates get_vp_point(unsigned int index) {return (index < points_count ? vp_points[index] : Coordinates(0, 0));}
        void compute_vp(void);
};

#endif