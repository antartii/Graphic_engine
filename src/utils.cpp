#include "utils.h"

Line::Line(Coordinates points[2])
{
    for (int i = 0; i < 2; i += 1)
        this->points[i] = points[i];
}

Line::Line(Coordinates starting_point, Coordinates vector)
{
    points[0] = starting_point;
    points[1] = Coordinates(starting_point.x + vector.x, starting_point.y + vector.y, starting_point.z + vector.z);
}