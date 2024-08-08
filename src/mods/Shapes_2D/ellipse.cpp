#include "ellipse.h"

Ellipse::Ellipse(Coordinates center, float radius[2])
{
    for (int i = 0; i < 2; i += 1) this->radius[i] = radius[i];
    this->center = center;
    points.clear();
    points = Ellipse::compute_points(center, radius);

    points_count = points.size();
    compute_vp();
}

std::vector<Coordinates> Ellipse::compute_points(Coordinates center, float radius[2])
{
    std::vector<Coordinates> points;
    Coordinates temp_point;
    float angle = 0;
    int segments_count = ((2 * M_PI * (maximum(radius[0], radius[1]) / 2)) / CURVES_SEGMENTS_LENGHT);

    if (segments_count < 3)
        segments_count = 3;
    for (int i = 0; i < segments_count; i += 1) {
        angle = 2.0f * M_PI * i / segments_count;
        temp_point.x = radius[0] * cos(angle) + center.x;
        temp_point.y = radius[1] * sin(angle) + center.y;
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
