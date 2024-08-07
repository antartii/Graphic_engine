#ifndef SHAPES_2D_QUAD
#define SHAPES_2D_QUAD

#include "utils.h"
#include "engine.h"

class Quad {
    private:
        Coordinates points[4];
        Coordinates vp_points[4];
    
    public :
        Quad() {};
        Quad(Coordinates p1, Coordinates p2, Coordinates p3, Coordinates p4);

        Coordinates get_point(unsigned int index) {return (index < 4 ? points[index] : Coordinates(0, 0));}
        Coordinates get_vp_point(unsigned int index) {return (index < 4 ? vp_points[index] : Coordinates(0, 0));}
        void set_point(unsigned int index, Coordinates point);
        void compute_vp(void);

        static void draw(Quad quad, Color color);
};

#endif