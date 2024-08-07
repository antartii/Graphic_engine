#include "triangle.h"

Triangle::Triangle(Coordinates p1, Coordinates p2, Coordinates p3)
{
    points[0] = p1;
    points[1] = p2;
    points[2] = p3;

    compute_vp();
}

void Triangle::set_point(unsigned int index, Coordinates point)
{
    if (index < 3) {
        points[index] = point;
        vp_points[index] = Engine::coordinates_to_vp(point);
    }
}

void Triangle::compute_vp(void)
{
    for (int i = 0; i < 3; i += 1)
        vp_points[i] = Engine::coordinates_to_vp(points[i]);
}
