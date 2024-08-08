#ifndef SHAPES_2D_BEZIER_CURVES
#define SHAPES_2D_BEZIER_CURVES

#include "utils.h"

class Bezier_curve
{
    private :
        std::vector<Coordinates> control_points;
        

    public :
        Bezier_curve(){}
        Bezier_curve(std::vector<Coordinates> control_points) {this->control_points = control_points;}

        static std::vector<Coordinates> compute_points(std::vector<Coordinates> control_points);
};

#endif