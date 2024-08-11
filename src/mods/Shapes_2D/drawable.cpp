#include "drawable.h"

void Drawable::add(Coordinates new_point)
{
    points.push_back(new_point);
    points_count += 1;
    compute_vp();
}

void Drawable::add(std::vector<Coordinates> new_points)
{
    int new_points_lenght = new_points.size();

    for (int i = 0; i < new_points_lenght; i += 1)
        points.push_back(new_points[i]);
    points_count += new_points_lenght;
    compute_vp();
}

void Drawable::add(Line new_line)
{
    for (int i = 0; i < 2; i += 1)
        points.push_back(new_line.get_point(i));
    points_count += 2;
    compute_vp();
}

void Drawable::add(Triangle new_triangle)
{
    for (int i = 0; i < 3; i += 1)
        points.push_back(new_triangle.get_point(i));
    points_count += 3;
    compute_vp();
}

void Drawable::add(Quad new_quad)
{
    for (int i = 0; i < 4; i += 1)
        points.push_back(new_quad.get_point(i));
    points_count += 4;
    compute_vp();
}

void Drawable::add(Polygon new_polygon)
{
    int polygon_points_count = new_polygon.get_points_count();

    for (int i = 0; i < polygon_points_count; i += 1)
        points.push_back(new_polygon.get_point(i));
    points_count += polygon_points_count;
    compute_vp();
}

void Drawable::add(Circle new_circle)
{
    int circle_points_count = new_circle.get_points_count();

    for (int i = 0; i < circle_points_count; i += 1)
        points.push_back(new_circle.get_point(i));
    points_count += circle_points_count;
    compute_vp();
}

void Drawable::add(Ellipse new_ellipse)
{
    int ellipse_points_count = new_ellipse.get_points_count();

    for (int i = 0; i < ellipse_points_count; i += 1)
        points.push_back(new_ellipse.get_point(i));
    points_count += ellipse_points_count;
    compute_vp();
}

void Drawable::add(Bezier_curve new_bezier_curve)
{
    int bezier_curve_points_count = new_bezier_curve.get_points_count();

    for (int i = 0; i < bezier_curve_points_count; i += 1)
        points.push_back(new_bezier_curve.get_point(i));
    points_count += bezier_curve_points_count;
    compute_vp();
}

void Drawable::compute_vp()
{
    vp_points.clear();
    for (int i = 0; i < points_count; i += 1)
        vp_points.push_back(Engine::coordinates_to_vp(points[i]));
}