#include "circle.h"

Circle::Circle(Coordinates center, float radius, float angle, float rotation)
{
    this->angle = angle;
    this->rotation = rotation;
    points.clear();
    points = Circle::compute_points(center, radius, angle, rotation);
    points_count = points.size();
    compute_vp();
}

std::vector<Coordinates> Circle::compute_points(Coordinates center, float radius, float angle, float rotation)
{
    std::vector<Coordinates> points;
    Coordinates temp_point;
    float segment_angle = 0;
    int segments_count = Math::get_circle_circonference(radius) / CURVES_MAX_SEGMENTS_LENGTH;

    if (segments_count < 3)
        segments_count = 3;
    points.push_back(center);
    for (int i = 0; i <= segments_count / (360.0f / angle); i += 1) {
        segment_angle = (Math::get_circle_circonference(i) / segments_count) + Math::deg_to_rad(rotation);
        temp_point = Math::polar_coordinate(radius, segment_angle) + center;
        points.push_back(temp_point);
    }
    points.push_back(center);
    return points;
}

void Circle::set_radius(float radius)
{
    points = Circle::compute_points(center, radius, angle, rotation);
    points_count = points.size();
    for (unsigned int i = 0; i < points_count; i += 1)
        vp_points.push_back(Engine::coordinates_to_vp(points[i]));
}

void Circle::set_center(Coordinates center)
{
    
    points = Circle::compute_points(center, radius, angle, rotation);
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