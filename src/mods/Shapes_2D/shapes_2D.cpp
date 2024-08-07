#include "shapes_2D.h"

Line *Shapes_2D::create_line(Line line)
{
    instance->lines.push_back(line);
    return &instance->lines.back();
}

Quad *Shapes_2D::create_quad(Quad quad)
{
    instance->quads.push_back(quad);
    return &instance->quads.back();
}

Triangle *Shapes_2D::create_triangle(Triangle triangle)
{
    instance->triangles.push_back(triangle);
    return &instance->triangles.back();
}

Polygon *Shapes_2D::create_polygon(Polygon polygon)
{
    instance->polygons.push_back(polygon);
    return &instance->polygons.back();
}

Circle *Shapes_2D::create_circle(Circle circle)
{
    instance->circles.push_back(circle);
    return &instance->circles.back();
}

void Shapes_2D::delete_shape(unsigned int index, TYPES type)
{
    switch (type) {
        case LINE:
            instance->lines.erase(instance->lines.begin() + index);
            break;
        case TRIANGLE:
            instance->triangles.erase(instance->triangles.begin() + index);
            break;
        case QUAD :
            instance->quads.erase(instance->quads.begin() + index);
            break;
        case POLYGON :
            instance->polygons.erase(instance->polygons.begin() + index);
            break;
        case CIRCLE :
            instance->circles.erase(instance->circles.begin() + index);
            break;
        default:
            break;
    }
}

void Shapes_2D::compute_vp(void)
{
    int lines_count = instance->lines.size();
    int triangles_count = instance->lines.size();
    int quads_count = instance->quads.size();
    int polygons_count = instance->polygons.size();
    int circles_count = instance->circles.size();

    for (int i = 0; i < lines_count; i += 1) instance->lines[i].compute_vp();
    for (int i = 0; i < triangles_count; i += 1) instance->triangles[i].compute_vp();
    for (int i = 0; i < quads_count; i += 1) instance->quads[i].compute_vp();
    for (int i = 0; i < polygons_count; i += 1) instance->polygons[i].compute_vp();
    for (int i = 0; i < circles_count; i += 1) instance->circles[i].compute_vp();
}
