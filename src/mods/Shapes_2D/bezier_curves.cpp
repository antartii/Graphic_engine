#include "bezier_curves.h"

Bezier_curve::Bezier_curve(std::vector<Coordinates> control_points)
{
    this->control_points = control_points;
    points = compute_points(control_points);
    points_count = points.size();
    compute_vp();
}

std::vector<Coordinates> Bezier_curve::compute_points(std::vector<Coordinates> control_points)
{
    std::vector<Coordinates> points;
    long double t = 0;
    int control_polygon_lenght = 0;
    int segments_count = 0;
    Coordinates temp_point;
    int n = control_points.size() - 1;
    long double term = 0;

    for (int i = 0; i <= n; i += 1)
        control_polygon_lenght += Math::distance(control_points[i], control_points[i + 1]);
    segments_count = control_polygon_lenght / CURVES_MAX_SEGMENTS_LENGTH;
    for (int i = 0; i <= segments_count; i += 1) {
        t = (long double) i / segments_count;
        temp_point = Coordinates(0, 0);
        for (int j = 0; j <= n; j += 1) {
            term = Math::binomial_coef(n, j) * Math::pow(1 - t, n - j) * Math::pow(t, j);
            temp_point.x += term * control_points[j].x;
            temp_point.y += term * control_points[j].y;
        }
        points.push_back(temp_point);
    }
    return points;
}

void Bezier_curve::compute_vp()
{
    vp_points.clear();
    for (int i = 0; i < points_count; i += 1) {
        vp_points.push_back(Engine::coordinates_to_vp(points[i]));
    }
}
