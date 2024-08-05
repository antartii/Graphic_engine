#include "engine.h"

Engine::Engine(int *argc, char **argv):
    argc(*argc), argv(argv)
{
    glutInit(argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // BY DEFAULT (do dev want to set it manually ?)
}

void Engine::add_mod_update_function(void (*mod_update_function)(int, int))
{
    this->mod_update_functions.push_back(mod_update_function);
    mod_update_functions_count += 1;
}

void Engine::add_mod_display_function(void (*mod_display_function)())
{
    this->mod_display_functions.push_back(mod_display_function);
    mod_display_functions_count += 1;
}

void Engine::add_mod_init_function(void (*mod_init_function)())
{
    this->mod_init_functions.push_back(mod_init_function);
    mod_init_functions_count += 1;
}

void Engine::init()
{
    for (int i = 0; i < mod_init_functions_count; i += 1)
        mod_init_functions[i]();
}

void Engine::start()
{
    glutCreateWindow(window_title.c_str());
    glutTimerFunc(600 / fps, Engine::update_callback, 0);
    glutDisplayFunc(Engine::display_callback);
    glutReshapeFunc(Engine::reshape_callback);
    glutInitWindowSize(window_size.width, window_size.height);
    glutInitWindowPosition(window_position.x, window_position.y);
    glPointSize(1.0f);

    glutMainLoop();
}

void Engine::draw(Coordinates point, Color color)
{
    Coordinates vp_point = coordinates_to_vp(point);

    glColor3f(color.r, color.g, color.b);
    glBegin(GL_POINTS);
    glVertex2f(vp_point.x, vp_point.y);
    glEnd();
}

void Engine::draw(Line line, Color color)
{
    Line vp_line = Engine::line_to_vp(line);

    glColor3f(color.r, color.g, color.b);
    glBegin(GL_LINES);
    glVertex2d(vp_line.p1.x, vp_line.p1.y);
    glVertex2d(vp_line.p2.x, vp_line.p2.y);
    glEnd();
}

void Engine::draw(Triangle triangle, Color color)
{
    Triangle vp_triangle = Engine::triangle_to_vp(triangle);

    glColor3f(color.r, color.g, color.b);
    glBegin(GL_TRIANGLES);
    glVertex2d(vp_triangle.p1.x, vp_triangle.p1.y);
    glVertex2d(vp_triangle.p2.x, vp_triangle.p2.y);
    glVertex2d(vp_triangle.p3.x, vp_triangle.p3.y);
    glEnd();
}

void Engine::draw(Quad quad, Color color)
{
    Quad vp_quad = Engine::quad_to_vp(quad);

    glColor3f(color.r, color.g, color.b);
    glBegin(GL_QUADS);
    glVertex2d(vp_quad.p1.x, vp_quad.p1.y);
    glVertex2d(vp_quad.p2.x, vp_quad.p2.y);
    glVertex2d(vp_quad.p3.x, vp_quad.p3.y);
    glVertex2d(vp_quad.p4.x, vp_quad.p4.y);
    glEnd();
}

void Engine::draw(Polygon polygon, Color color)
{
    Polygon vp_polygon = Engine::polygon_to_vp(polygon);

    glColor3f(color.r, color.g, color.b);
    glBegin(GL_POLYGON);
    for (int i = 0; i < vp_polygon.points.size(); i += 1)
        glVertex2d(vp_polygon.points[i].x, vp_polygon.points[i].y);
    glEnd();
}

/*void Engine::draw(Circle circle, Color color)
{
    Circle vp_circle = Engine::circle_to_vp(circle);
    std::vector<Coordinates> vp_points = vp_circle.get_points();

    glColor3f(color.r, color.g, color.b);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < vp_points.size(); i += 1)
        glVertex2d(vp_points[i].x, vp_points[i].y);
    glEnd();
}*/

void Engine::update(int fps, int value)
{
    for (int i = 0; i < mod_update_functions_count; i += 1)
        mod_update_functions[i](fps, value);
    glutPostRedisplay();
    glutTimerFunc(600 / fps, Engine::update_callback, 0);
}

void Engine::display()
{
    glClear(GL_COLOR_BUFFER_BIT);    
    for (int i = 0; i < mod_display_functions_count; i += 1)
        mod_display_functions[i]();
    glutSwapBuffers();
}

void Engine::reshape(int w, int h)
{
    window_size.width = w;
    window_size.height = h;
    glViewport(0, 0, w, h);
}

Coordinates Engine::coordinates_to_vp(Coordinates point)
{
    Coordinates vp_point(0, 0);
    Size window = Engine::get_window_size_callback();

    vp_point.x = (point.x / (window.width / 2)) - 1;
    vp_point.y = (point.y / (window.height / 2)) - 1;
    return vp_point;
}

Line Engine::line_to_vp(Line line)
{
    Line vp_line;

    vp_line.p1 = Engine::coordinates_to_vp(line.p1);
    vp_line.p2 = Engine::coordinates_to_vp(line.p2);
    return vp_line;
}

Triangle Engine::triangle_to_vp(Triangle triangle)
{
    Triangle vp_triangle;

    vp_triangle.p1 = Engine::coordinates_to_vp(triangle.p1);
    vp_triangle.p2 = Engine::coordinates_to_vp(triangle.p2);
    vp_triangle.p3 = Engine::coordinates_to_vp(triangle.p3);
    return vp_triangle;
}

Quad Engine::quad_to_vp(Quad quad)
{
    Quad vp_quad;

    vp_quad.p1 = Engine::coordinates_to_vp(quad.p1);
    vp_quad.p2 = Engine::coordinates_to_vp(quad.p2);
    vp_quad.p3 = Engine::coordinates_to_vp(quad.p3);
    vp_quad.p4 = Engine::coordinates_to_vp(quad.p4);
    return vp_quad;
}

Polygon Engine::polygon_to_vp(Polygon polygon)
{
    Polygon vp_polygon;

    for (int i = 0; i < polygon.points.size(); i += 1)
        vp_polygon.points.push_back(Engine::coordinates_to_vp(polygon.points[i]));
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
