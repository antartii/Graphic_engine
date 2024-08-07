#include "quad.h"

Quad::Quad(Coordinates p1, Coordinates p2, Coordinates p3, Coordinates p4)
{
    points[0] = p1;
    points[1] = p2;
    points[2] = p3;
    points[3] = p4;

    compute_vp();
}

void Quad::set_point(unsigned int index, Coordinates point)
{
    if (index < 4) {
        points[index] = point;
        vp_points[index] = Engine::coordinates_to_vp(point);
    }
}

void Quad::compute_vp(void)
{
    for (int i = 0; i < 4; i += 1)
        vp_points[i] = Engine::coordinates_to_vp(points[i]);
}

void Quad::draw(Quad quad, Color color)
{
    glColor3f(color.r, color.g, color.b);
    glBegin(GL_QUADS);
    for (int i = 0; i < 4; i += 1)
        glVertex2d(quad.get_vp_point(i).x, quad.get_vp_point(i).y);
    glEnd();
}