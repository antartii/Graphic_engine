#ifndef SHAPES_2D_LINE
#define SHAPES_2D_LINE

#include "utils.h"
#include "engine.h"

class Line {
    private :
        Coordinates points[2];
        Coordinates vp_points[2];

    public :
        Line(){}
        Line(Coordinates p1, Coordinates p2);
        Coordinates get_point(unsigned int index) {return (index < 2 ? points[index] : Coordinates(0, 0));}
        Coordinates get_vp_point(unsigned int index) {return (index < 2 ? vp_points[index] : Coordinates(0, 0));}
        void set_point(unsigned int index, Coordinates point);

        static void draw(Line line, Color color);
};

#endif