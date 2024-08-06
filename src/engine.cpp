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
