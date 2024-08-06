#include "line.h"

Line::Line(Coordinates p1, Coordinates p2)
{
    points[0] = p1;
    points[1] = p2;

    for (int i = 0; i < 2; i += 1)
        vp_points[i] = Engine::coordinates_to_vp(points[i]);
}

void Line::set_point(unsigned int index, Coordinates point)
{
    if (index < 2) {
        points[index] = point;
        vp_points[index] = Engine::coordinates_to_vp(point);
    }
}

void Line::draw(Line line, Color color)
{
    glColor3f(color.r, color.g, color.b);
    glBegin(GL_LINES);
    for (int i = 0; i < 2; i += 1)
        glVertex2d(line.get_vp_point(i).x, line.get_vp_point(i).y);
    glEnd();
}