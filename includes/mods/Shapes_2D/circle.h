#ifndef SHAPES_2D_CIRCLE
#define SHAPES_2D_CIRCLE

#include <vector>
#include "utils.h"
#include "engine.h"
#include <cmath>

#ifndef CURVES_SEGMENTS_LENGHT
#define CURVES_SEGMENTS_LENGHT 1
#endif

class Circle {
    private :
        float radius = 0;
        Coordinates center;

        unsigned int points_count = 0;
        std::vector<Coordinates> points;
        std::vector<Coordinates> vp_points;

    public :
        Circle() {}
        Circle(Coordinates center, float radius);

        Coordinates get_point(unsigned int index) {return (index < points_count ? points[index] : Coordinates(0, 0));}
        Coordinates get_vp_point(unsigned int index) {return (index < points_count ? vp_points[index] : Coordinates(0, 0));}
        int get_points_count(void) {return points_count;}
        void set_radius(float radius);
        void set_center(Coordinates center);
        void compute_vp(void);

        static void draw(Circle polygon, Color color);
        static std::vector<Coordinates> compute_points(Coordinates center, float radius);
};

#endif