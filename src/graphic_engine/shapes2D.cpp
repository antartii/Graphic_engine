#include "shapes2D.h"

Shapes2D::Quad::Quad(Shapes2D::Coord2D start, Shapes2D::Coord2D end)
{
    GLfloat x_low_axis = 0;
    GLfloat x_high_axis = 0;
    GLfloat y_low_axis = 0;
    GLfloat y_high_axis = 0;

    if (start.x < end.x)
    {
        x_low_axis = start.x;
        x_high_axis = end.x;
    }
    else
    {
        x_low_axis = end.x;
        x_high_axis = start.x;
    }
    if (start.y < end.y)
    {
        y_low_axis = start.y;
        y_high_axis = end.y;
    }
    else
    {
        y_low_axis = end.y;
        y_high_axis = start.y;
    }
    this->start = Coord2D(x_low_axis, y_low_axis);
    this->end = Coord2D(x_high_axis, y_high_axis);
    this->width = end.x - start.x;
    this->height = end.y - start.y;
}

Shapes2D::Coord2D Shapes2D::Quad::get_point(DIRECTION direction)
{
    switch (direction)
    {
    case DIRECTION::BOTTOM_LEFT:
        return start;
    case DIRECTION::LEFT:
        return Coord2D(start.x, start.y + (width / 2.0f));
    case DIRECTION::TOP_LEFT:
        return Coord2D(start.x, end.y);
    case DIRECTION::TOP:
        return Coord2D(start.x + (width / 2.0f), end.y);
    case DIRECTION::TOP_RIGHT:
        return end;
    case DIRECTION::RIGHT:
        return Coord2D(end.x, start.y + (width / 2.0f));
    case DIRECTION::BOTTOM_RIGHT:
        return Coord2D(end.x, start.y);
    case DIRECTION::BOTTOM:
        return Coord2D(start.x + (width / 2.0f), start.y);
    default:
        return Coord2D(0, 0);
    }
}

GLboolean Shapes2D::Quad::is_contained(Coord2D pos)
{
    GLfloat x_low_axis = start.x;
    GLfloat x_high_axis = end.x;
    GLfloat y_low_axis = start.y;
    GLfloat y_high_axis = end.y;

    if (pos.x >= x_low_axis && pos.x <= x_high_axis && pos.y >= y_low_axis && pos.y <= y_high_axis)
        return true;
    else
        return false;
}
