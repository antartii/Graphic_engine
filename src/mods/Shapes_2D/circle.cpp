#include "circle.h"

Circle::Circle(Coordinates center, float radius)
{
    points.clear();
    points = Circle::compute_points(center, radius);
    points_count = points.size();
    compute_vp();
}

std::vector<Coordinates> Circle::compute_points(Coordinates center, float radius)
{
    std::vector<Coordinates> points;
    Coordinates temp_point;
    float angle = 0;
    int segments_count = Math::get_circle_circonference(radius) / CURVES_MAX_SEGMENTS_LENGTH;

    if (segments_count < 3)
        segments_count = 3;
    for (int i = 0; i < segments_count + 1; i += 1) {
        angle = Math::get_circle_radian(i) / segments_count;
        temp_point = Math::polar_coordinate(radius, angle) + center;
        points.push_back(temp_point);
    }
    return points;
}

void Circle::set_radius(float radius)
{
    points = Circle::compute_points(center, radius);
    points_count = points.size();
    for (unsigned int i = 0; i < points_count; i += 1)
        vp_points.push_back(Engine::coordinates_to_vp(points[i]));
}

void Circle::set_center(Coordinates center)
{
    
    points = Circle::compute_points(center, radius);
    points_count = points.size();
    for (unsigned int i = 0; i < points_count; i += 1)
        vp_points.push_back(Engine::coordinates_to_vp(points[i]));
}

void Circle::compute_vp()
{
    vp_points.clear();
    for (unsigned int i = 0; i < points_count; i += 1)
        vp_points.push_back(Engine::coordinates_to_vp(points[i]));
}