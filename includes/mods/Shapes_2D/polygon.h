#ifndef SHAPES_2D_POLYGON
#define SHAPES_2D_POLYGON

#include "engine.h"
#include "utils.h"
#include <cmath>

class Polygon {
    private :
        std::vector<Coordinates> points;
        std::vector<Coordinates> vp_points;
        int points_count = 0;

    public :
        Polygon() {};
        Polygon(std::vector<Coordinates> points);

        Coordinates get_point(unsigned int index) {return (index < points_count ? points[index] : Coordinates(0, 0));}
        Coordinates get_vp_point(unsigned int index) {return (index < points_count ? vp_points[index] : Coordinates(0, 0));}
        void set_point(unsigned int index, Coordinates point);
        int get_points_count(void) {return points_count;}
        void add_point(Coordinates point);
        void compute_vp(void);

        static void draw(Polygon polygon, Color color);
};

#endif