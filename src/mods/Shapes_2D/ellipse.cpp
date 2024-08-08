#include "ellipse.h"

Ellipse::Ellipse(Coordinates center, float radius[2], float rotation_angle)
{
    for (int i = 0; i < 2; i += 1) this->radius[i] = radius[i];
    this->center = center;
    this->rotation_angle = rotation_angle;
    points.clear();
    points = Ellipse::compute_points(center, radius, rotation_angle);

    points_count = points.size();
    compute_vp();
}

std::vector<Coordinates> Ellipse::compute_points(Coordinates center, float radius[2], float rotation_angle)
{
    std::vector<Coordinates> points;
    Coordinates temp_point;
    float angle = 0;
    int segments_count = ((2 * M_PI * (maximum(radius[0], radius[1]) / 2)) / CURVES_SEGMENTS_LENGHT);
    Coordinates rotated;
    float rotation_angle_radiant = rotation_angle * M_PI / 180.0f;
    
    if (segments_count < 3)
        segments_count = 3;
    for (int i = 0; i < segments_count; i += 1) {
        angle = 2.0f * M_PI * i / segments_count;
        temp_point.x = radius[0] * cos(angle);
        temp_point.y = radius[1] * sin(angle);

        rotated.x = temp_point.x * cos(rotation_angle_radiant) - temp_point.y * sin(rotation_angle_radiant);
        rotated.y = temp_point.x * sin(rotation_angle_radiant) + temp_point.y * cos(rotation_angle_radiant);

        temp_point.x = rotated.x + center.x;
        temp_point.y = rotated.y + center.y;

        points.push_back(temp_point);
    }

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
        points = compute_points(center, this->radius, rotation_angle);
        compute_vp();
    }
}

void Ellipse::set_center(Coordinates center)
{
    this->center = center;
    points = compute_points(center, this->radius, rotation_angle);
    compute_vp();
}
