#ifndef SHAPES_2D_TRIANGLE
    #define SHAPESS_2D_TRIANGLE

    #include "utils.h"
    #include "engine.h"

class Triangle {
    private :
        Coordinates points[3];
        Coordinates vp_points[3];
    public :
        Triangle() {};
        Triangle(Coordinates p1, Coordinates p2, Coordinates p3);

        Coordinates get_point(unsigned int index) {return (index < 3 ? points[index] : Coordinates(0, 0));}
        Coordinates get_vp_point(unsigned int index) {return (index < 3 ? vp_points[index] : Coordinates(0, 0));}
        void set_point(unsigned int index, Coordinates point);

        static void draw(Triangle triangle, Color color);
};

#endif