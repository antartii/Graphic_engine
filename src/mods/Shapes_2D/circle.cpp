#include "circle.h"

Circle::Circle(Coordinates center, float radius)
{
    points = Circle::compute_points(center, radius);
    points_count = points.size();
    for (int i = 0; i < points_count; i += 1)
        vp_points.push_back(Engine::coordinates_to_vp(points[i]));
}

void Circle::draw(Circle circle, Color color)
{
    glColor3f(color.r, color.g, color.b);
    glBegin(GL_POLYGON);
    for (int i = 0; i < circle.get_points_count(); i += 1)
        glVertex2d(circle.get_vp_point(i).x, circle.get_vp_point(i).y);
    glEnd();
}

std::vector<Coordinates> Circle::compute_points(Coordinates center, float radius)
{
    std::vector<Coordinates> points;
    Coordinates temp_point;
    float angle = 0;
    int segments_count = (2 * M_PI * radius) / CURVES_SEGMENTS_LENGHT;

    if (segments_count < 3)
        segments_count = 3;

    for (int i = 0; i < segments_count; i += 1) {
        angle = 2.0f * M_PI * i / segments_count;
        temp_point.x = radius * cos(angle) + center.x;
        temp_point.y = radius * sin(angle) + center.y;
        points.push_back(temp_point);
    }
    return points;
}

void Circle::set_radius(float radius)
{
    points = Circle::compute_points(center, radius);
    points_count = points.size();
    for (int i = 0; i < points_count; i += 1)
        vp_points.push_back(Engine::coordinates_to_vp(points[i]));
}

void Circle::set_center(Coordinates center)
{
    
    points = Circle::compute_points(center, radius);
    points_count = points.size();
    for (int i = 0; i < points_count; i += 1)
        vp_points.push_back(Engine::coordinates_to_vp(points[i]));
}