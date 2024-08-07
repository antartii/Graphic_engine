#include "line.h"

Line::Line(Coordinates p1, Coordinates p2)
{
    points[0] = p1;
    points[1] = p2;

    compute_vp();
}

void Line::set_point(unsigned int index, Coordinates point)
{
    if (index < 2) {
        points[index] = point;
        vp_points[index] = Engine::coordinates_to_vp(point);
    }
}

void Line::compute_vp(void)
{
    for (int i = 0; i < 2; i += 1)
        vp_points[i] = Engine::coordinates_to_vp(points[i]);
}
