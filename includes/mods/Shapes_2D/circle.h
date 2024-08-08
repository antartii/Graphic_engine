#ifndef SHAPES_2D_CIRCLE
#define SHAPES_2D_CIRCLE

#include <vector>
#include "utils.h"
#include "engine.h"
#include "math.h"

#ifndef CURVES_MAX_SEGMENTS_LENGTH
#define CURVES_MAX_SEGMENTS_LENGTH 1
#endif

class Circle {
    private :
        float radius = 0;
        Coordinates center;
        float angle_start = 0;
        float angle_end = 360;

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

        static std::vector<Coordinates> compute_points(Coordinates center, float radius);
};

#endif