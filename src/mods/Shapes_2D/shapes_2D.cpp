#include "shapes_2D.h"

Shapes2D::Line Shapes2D::line_to_vp(Line line, Size window)
{
    Line vp_line;

    vp_line.p1 = Coordinates::coordinates_to_vp(line.p1, window);
    vp_line.p2 = Coordinates::coordinates_to_vp(line.p2, window);
    return vp_line;
}

Shapes2D::Triangle Shapes2D::triangle_to_vp(Triangle triangle, Size window)
{
    Triangle vp_triangle;

    vp_triangle.p1 = Coordinates::coordinates_to_vp(triangle.p1, window);
    vp_triangle.p2 = Coordinates::coordinates_to_vp(triangle.p2, window);
    vp_triangle.p3 = Coordinates::coordinates_to_vp(triangle.p3, window);
    return vp_triangle;
}

Shapes2D::Quad Shapes2D::quad_to_vp(Quad quad, Size window)
{
    Quad vp_quad;

    vp_quad.p1 = Coordinates::coordinates_to_vp(quad.p1, window);
    vp_quad.p2 = Coordinates::coordinates_to_vp(quad.p2, window);
    vp_quad.p3 = Coordinates::coordinates_to_vp(quad.p3, window);
    vp_quad.p4 = Coordinates::coordinates_to_vp(quad.p4, window);
    return vp_quad;
}

Shapes2D::Polygon Shapes2D::polygon_to_vp(Polygon polygon, Size window)
{
    Polygon vp_polygon;

    for (int i = 0; i < polygon.points.size(); i += 1)
        vp_polygon.points.push_back(Coordinates::coordinates_to_vp(polygon.points[i], window));
    return vp_polygon;
}

/*Circle Engine::circle_to_vp(Circle circle)
{
    float vp_radius = 0.5;
    Coordinates vp_center = coordinates_to_vp(circle.get_center());
    int segments_count = circle.get_segments_count();
    Circle vp_circle(vp_center, vp_radius, segments_count);

    return vp_circle;
}*/

void Shapes2D::draw(Line line, Color color, Size window)
{
    Line vp_line = Shapes2D::line_to_vp(line, window);

    glColor3f(color.r, color.g, color.b);
    glBegin(GL_LINES);
    glVertex2d(vp_line.p1.x, vp_line.p1.y);
    glVertex2d(vp_line.p2.x, vp_line.p2.y);
    glEnd();
}

void Shapes2D::draw(Triangle triangle, Color color, Size window)
{
    Triangle vp_triangle = Shapes2D::triangle_to_vp(triangle, window);

    glColor3f(color.r, color.g, color.b);
    glBegin(GL_TRIANGLES);
    glVertex2d(vp_triangle.p1.x, vp_triangle.p1.y);
    glVertex2d(vp_triangle.p2.x, vp_triangle.p2.y);
    glVertex2d(vp_triangle.p3.x, vp_triangle.p3.y);
    glEnd();
}

void Shapes2D::draw(Quad quad, Color color, Size window)
{
    Quad vp_quad = Shapes2D::quad_to_vp(quad, window);

    glColor3f(color.r, color.g, color.b);
    glBegin(GL_QUADS);
    glVertex2d(vp_quad.p1.x, vp_quad.p1.y);
    glVertex2d(vp_quad.p2.x, vp_quad.p2.y);
    glVertex2d(vp_quad.p3.x, vp_quad.p3.y);
    glVertex2d(vp_quad.p4.x, vp_quad.p4.y);
    glEnd();
}

void Shapes2D::draw(Polygon polygon, Color color, Size window)
{
    Polygon vp_polygon = Shapes2D::polygon_to_vp(polygon, window);

    glColor3f(color.r, color.g, color.b);
    glBegin(GL_POLYGON);
    for (int i = 0; i < vp_polygon.points.size(); i += 1)
        glVertex2d(vp_polygon.points[i].x, vp_polygon.points[i].y);
    glEnd();
}

/*void Shapes2D::draw(Circle circle, Color color)
{
    Circle vp_circle = Shapes2D::circle_to_vp(circle);
    std::vector<Coordinates> vp_points = vp_circle.get_points();

    glColor3f(color.r, color.g, color.b);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < vp_points.size(); i += 1)
        glVertex2d(vp_points[i].x, vp_points[i].y);
    glEnd();
}*/

/*Circle::Circle(Coordinates center, float radius, int segments_count)
{
    float angle = 0;
    Coordinates point;

    this->center = center;
    this->radius = radius;
    this->segments_count = segments_count;

    for (int i = 0; i < segments_count; i += 1) {
        angle = 2.0f * M_PI * i / segments_count;
        point.x = radius * cos(angle) + center.y;
        point.y = radius * sin(angle) + center.x;
        points.push_back(point);
    }
}*/
