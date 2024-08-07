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
