#include "ellipse.h"

Ellipse::Ellipse(Coordinates center, float radius[2], float angle, float rotation_angle)
{
    for (int i = 0; i < 2; i += 1) this->radius[i] = radius[i];
    this->center = center;
    this->rotation_angle = rotation_angle;
    this->angle = angle;
    points.clear();
    points = Ellipse::compute_points(center, radius, angle, rotation_angle);
    points_count = points.size();
    compute_vp();
}

std::vector<Coordinates> Ellipse::compute_points(Coordinates center, float radius[2], float angle, float rotation_angle)
{
    std::vector<Coordinates> points;
    Coordinates temp_point;
    float segment_angle = 0;
    int segments_count = (Math::get_circle_circonference(Math::average({radius[0], radius[1]}))) / CURVES_MAX_SEGMENTS_LENGTH;
    Coordinates rotated;
    float rotation_angle_radian = Math::deg_to_rad(rotation_angle);

    if (segments_count < 3)
        segments_count = 3;
    points.push_back(center);
    for (int i = 0; i <= segments_count / (360.0f / angle); i += 1) {
        segment_angle = Math::get_circle_circonference(i) / segments_count;
        temp_point = Math::cartesian_coordinates(radius[0], radius[1], segment_angle);
        temp_point = Math::apply_rotation(temp_point, rotation_angle_radian) + center;
        points.push_back(temp_point);
    }
    points.push_back(center);
    return points;
}

void Ellipse::compute_vp(void)
{
    vp_points.clear();
    for (unsigned int i = 0; i < points_count; i += 1)
        vp_points.push_back(Engine::coordinates_to_vp(points[i]));
}

void Ellipse::set_radius(unsigned int index, float radius)
{
    if (index < 2) {
        this->radius[index] = radius;
        points = compute_points(center, this->radius, angle, rotation_angle);
        compute_vp();
    }
}

void Ellipse::set_center(Coordinates center)
{
    this->center = center;
    points = compute_points(center, this->radius, angle, rotation_angle);
    compute_vp();
}
