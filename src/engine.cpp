#include "engine.h"

Engine::Engine(int *argc, char **argv):
    argc(*argc), argv(argv)
{
    glutInit(argc, argv);
}

void Engine::add_plugin_update_function(void (*plugin_update_function)(int, int))
{
    this->plugin_update_functions.push_back(plugin_update_function);
    plugin_update_functions_count += 1;
}

void Engine::add_plugin_display_function(void (*plugin_display_function)())
{
    this->plugin_display_functions.push_back(plugin_display_function);
    plugin_display_functions_count += 1;
}

void Engine::add_plugin_init_function(void (*plugin_init_function)())
{
    this->plugin_init_functions.push_back(plugin_init_function);
    plugin_init_functions_count += 1;
}

void Engine::add_plugin_reshape_function(void (*plugin_reshape_function)())
{
    this->plugin_reshape_functions.push_back(plugin_reshape_function);
    plugin_reshape_functions_count += 1;
}

void Engine::set_window_title(std::string title)
{
    glutSetWindowTitle(title.c_str());
    window_title = title;
}

void Engine::set_window_size(Size size)
{
    glutReshapeWindow(size.width, size.height);
    window_size = size;
}

void Engine::set_window_pos(Coordinates pos)
{
    glutPositionWindow(pos.x, pos.y);
    window_position = pos;
}

void Engine::init()
{
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // BY DEFAULT (do dev want to set it manually ?)
    window_size = Size(glutGet(GLUT_SCREEN_WIDTH), glutGet(GLUT_SCREEN_HEIGHT));
    screen_size = Size(glutGet(GLUT_SCREEN_WIDTH), glutGet(GLUT_SCREEN_HEIGHT));
    glutInitWindowSize(window_size.width, window_size.height);
    glutInitWindowPosition(window_position.x, window_position.y);
    glutCreateWindow(window_title.c_str());
    glutTimerFunc(600 / fps, Engine::update_callback, 0);
    glutDisplayFunc(Engine::display_callback);
    glutReshapeFunc(Engine::reshape_callback);
    glPointSize(1.0f);
    set_background(background_color);
    for (int i = 0; i < plugin_init_functions_count; i += 1)
        plugin_init_functions[i]();
}

void Engine::start()
{
    init();
    glutMainLoop();
}

void Engine::update(int fps, int value)
{
    for (int i = 0; i < plugin_update_functions_count; i += 1)
        plugin_update_functions[i](fps, value);
    glutPostRedisplay();
    glutTimerFunc(600 / fps, Engine::update_callback, 0);
}

void Engine::display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    for (int i = 0; i < plugin_display_functions_count; i += 1)
        plugin_display_functions[i]();
    glutSwapBuffers();
}

void Engine::reshape(int w, int h)
{
    window_size.width = w;
    window_size.height = h;
    for (int i = 0; i < plugin_reshape_functions_count; i += 1)
        plugin_reshape_functions[i]();
    glViewport(0, 0, w, h);
}

Coordinates Engine::coordinates_to_vp(Coordinates point)
{
    Coordinates vp_point(0, 0);
    Size window = get_window_size_callback();

    vp_point.x = (point.x / (window.width / 2)) - 1;
    vp_point.y = (point.y / (window.height / 2)) - 1;
    return vp_point;
}

void Engine::draw(Coordinates point, Color color)
{
    Coordinates vp_point = coordinates_to_vp(point);

    glColor3f(color.r, color.g, color.b);
    glBegin(GL_POINTS);
    glVertex2f(vp_point.x, vp_point.y);
    glEnd();
}

void Engine::set_background(Color color)
{
    background_color = color.to_ratio();
    glClearColor(background_color.r, background_color.g, background_color.b, 1.0f);
}
