#ifndef SHAPES_2D_BEZIER_CURVES
#define SHAPES_2D_BEZIER_CURVES

#include "utils.h"
#include "mathematics.h"
#include "engine.h"
#ifndef CURVES_MAX_SEGMENTS_LENGTH
#define CURVES_MAX_SEGMENTS_LENGTH 1
#endif

class Bezier_curve
{
    private :
        std::vector<Coordinates> control_points;
        std::vector<Coordinates> points;
        std::vector<Coordinates> vp_points;
        int points_count = 0;

    public :
        Bezier_curve(){}
        Bezier_curve(std::vector<Coordinates> control_points);

        void compute_vp(void);
        int get_points_count(void) {return points_count;}
        Coordinates get_vp_point(unsigned int index) {return (index < points_count ? vp_points[index] : Coordinates(0, 0));}

        static std::vector<Coordinates> compute_points(std::vector<Coordinates> control_points);
        static std::vector<Coordinates> compute_points_quadratic(Coordinates control_points[3]);
        static std::vector<Coordinates> compute_points_cubic(Coordinates control_points[4]);
};

#endif