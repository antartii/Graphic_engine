#include "utils.h"

Coordinates Coordinates::coordinates_to_vp(Coordinates point, Size window)
{
    Coordinates vp_point(0, 0);

    vp_point.x = (point.x / (window.width / 2)) - 1;
    vp_point.y = (point.y / (window.height / 2)) - 1;
    return vp_point;
}

void Coordinates::draw(Coordinates point, Color color, Size window)
{
    Coordinates vp_point = coordinates_to_vp(point, window);

    glColor3f(color.r, color.g, color.b);
    glBegin(GL_POINTS);
    glVertex2f(vp_point.x, vp_point.y);
    glEnd();
}