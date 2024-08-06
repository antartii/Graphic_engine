#include "triangle.h"

Triangle::Triangle(Coordinates p1, Coordinates p2, Coordinates p3)
{
    points[0] = p1;
    points[1] = p2;
    points[2] = p3;

    for (int i = 0; i < 3; i += 1)
        vp_points[i] = Engine::coordinates_to_vp(points[i]);
}

void Triangle::set_point(unsigned int index, Coordinates point)
{
    if (index < 3) {
        points[index] = point;
        vp_points[index] = Engine::coordinates_to_vp(point);
    }
}

void Triangle::draw(Triangle triangle, Color color)
{
    glColor3f(color.r, color.g, color.b);
    glBegin(GL_TRIANGLES);
    for (int i = 0; i < 3; i += 1)
        glVertex2d(triangle.get_vp_point(i).x, triangle.get_vp_point(i).y);
    glEnd();
}
