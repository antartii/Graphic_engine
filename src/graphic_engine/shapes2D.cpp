#include "shapes2D.h"

Shapes2D::Coord2D Shapes2D::point_to_viewport(Coord2D point, Coord2D window_resolution)
{
    Shapes2D::Coord2D viewport_point = Coord2D(0, 0);

    viewport_point.x = screen_coord_to_viewport(point.x, window_resolution.x);
    viewport_point.y = screen_coord_to_viewport(point.y, window_resolution.y);
    return viewport_point;
}

GLboolean Shapes2D::is_contained(std::vector<Shapes2D::Line> shape_lines, Shapes2D::Coord2D point)
{
    // Drawing imaginary line that goes into the y axis up and if the number of lines hit is even, it is not contained
    GLint line_hit = 0;
    Coord2D A;
    Coord2D B;
    GLfloat y_hitting = 0; // where the "droite" is hitting the segment (we don't care if it's lower or higher)

    if (shape_lines.size() <= 2)
        return false;
    for (size_t i = 0; i < shape_lines.size(); i += 1) {
        A = shape_lines[i].points[0];
        B = shape_lines[i].points[1];
        if ((A.x > B.x && point.x < A.x && point.x > B.x) || (A.x < B.x && point.x > A.x && point.x < B.x)) {
            y_hitting = A.y + (point.x - A.x) * (B.y - A.y) / (B.x - A.x);
            if (y_hitting < point.y) // if the y is lower then it don't hit the point if it goes up in the y axis
                line_hit += 1;
        }
    }
    return (line_hit % 2 == 0 ? false : true);
}

std::map<std::string, Shapes2D::Coord2D> Shapes2D::Coord2D::extract_from_table(std::vector<std::vector<std::string>> table)
{
    std::map<std::string, Shapes2D::Coord2D> points;
    GLboolean is_reading = false;
    Shapes2D::Coord2D new_point;

    for (size_t i = 0; i < table.size(); i += 1) {
        if (table[i].size() == 1)
            table[i][0] == "POINTS" ? is_reading = true : is_reading = false;
        else if (is_reading && table[i].size() == 3)
            points.insert({table[i][0], Shapes2D::Coord2D(std::stof(table[i][1]), std::stof(table[i][2]))});
    }
    return points;
}

std::vector<Shapes2D::Line> Shapes2D::Quad::get_lines(void)
{
    std::vector<Line> lines;
    Coord2D line_points[2] = {Coord2D(0, 0), Coord2D(0, 0)};

    for (int i = 0; i < 4; i += 1) {
        line_points[0] = points[i];
        line_points[1] = points[(i + 1) % 4];
        lines.push_back(Line(line_points));
    }
    return lines;
}
