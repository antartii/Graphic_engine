#ifndef SHAPES_2D_ELLIPSE
#define SHAPES_2D_ELLIPSE

#include "utils.h"
#include "engine.h"
#include "mathematics.h"

#ifndef CURVES_MAX_SEGMENTS_LENGTH
#define CURVES_MAX_SEGMENTS_LENGTH 1
#endif

class Ellipse
{
    private :
        float radius[2] = {0, 0};
        Coordinates center;
        float rotation_angle = 0;

        unsigned int points_count = 0;
        std::vector<Coordinates> points;
        std::vector<Coordinates> vp_points;

    public :
        Ellipse() {};
        Ellipse(Coordinates center, float radius[2], float rotation_angle);

        int get_points_count(void) {return points_count;}
        Coordinates get_vp_point(unsigned int index) {return (index < points_count ? vp_points[index] : Coordinates(0, 0));}
        void set_radius(unsigned int index, float radius);
        void set_center(Coordinates center); // TODO 
        void compute_vp(void);

        static std::vector<Coordinates> compute_points(Coordinates center, float radius[2], float rotation_angle);
};

#endif