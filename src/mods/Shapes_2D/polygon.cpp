#include "polygon.h"

Polygon::Polygon(std::vector<Coordinates> points)
{
    points_count = points.size();
    this->points.clear();
    this->vp_points.clear();
    this->points = points;

    for (int i = 0; i < points_count; i += 1)
        this->vp_points.push_back(Engine::coordinates_to_vp(points[i]));
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

void Polygon::draw(Polygon polygon, Color color)
{
    glColor3f(color.r, color.g, color.b);
    glBegin(GL_POLYGON);
    for (int i = 0; i < polygon.get_points_count(); i += 1)
        glVertex2d(polygon.get_vp_point(i).x, polygon.get_vp_point(i).y);
    glEnd();
}

Polygon Polygon::create_circle(Coordinates center, float radius, int segments_count)
{
    std::vector<Coordinates> circle_points;
    Coordinates temp_point;
    float angle = 0;

    for (int i = 0; i < segments_count; i += 1) {
        angle = 2.0f * M_PI * i / segments_count;
        temp_point.x = radius * cos(angle) + center.x;
        temp_point.y = radius * sin(angle) + center.y;
        circle_points.push_back(temp_point);
    }
    return Polygon(circle_points);
}