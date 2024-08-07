#include "polygon.h"

Polygon::Polygon(std::vector<Coordinates> points)
{
    points_count = points.size();
    this->points.clear();
    this->points = points;
    compute_vp();
}

void Polygon::set_point(unsigned int index, Coordinates point)
{
    if (index < points_count) {
        points[index] = point;
        vp_points[index] = Engine::coordinates_to_vp(point);
    }
}

void Polygon::add_point(Coordinates point)
{
    points.push_back(point);
    vp_points.push_back(Engine::coordinates_to_vp(point));
}

void Polygon::compute_vp(void)
{
    vp_points.clear();
    for (unsigned int i = 0; i < points_count; i += 1)
        this->vp_points.push_back(Engine::coordinates_to_vp(points[i]));
}
