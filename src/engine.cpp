#include "engine.h"

Engine::Engine(int *argc, char **argv):
    argc(*argc), argv(argv)
{
    glutInit(argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // BY DEFAULT (do dev want to set it manually ?)
}

void Engine::init(std::string title, Size size, Coordinates position)
{
    window_size = size;
    window_position = position;
    window_title = title;
}

void Engine::start()
{
    glutCreateWindow(window_title.c_str());
    glutTimerFunc(600 / fps, Engine::update_callback, 0);
    glutDisplayFunc(Engine::display_callback);
    glutReshapeFunc(Engine::reshape_callback);
    glutInitWindowSize(window_size.width, window_size.height);
    glutInitWindowPosition(window_position.x, window_position.y);
    glutMainLoop();
}

void Engine::draw(Coordinates point)
{
    Coordinates vp_point = Coordinates_to_vp(point);

    std::cout << "point : " << vp_point.x << ", " << vp_point.y << std::endl;

    glPointSize(1.0f);
    glBegin(GL_POINTS);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(vp_point.x, vp_point.y);
    glEnd();
}

void Engine::update(int fps, int value)
{
    if (game_manager != nullptr)
        game_manager->update();
    glutPostRedisplay();
    glutTimerFunc(600 / fps, Engine::update_callback, 0);
}

void Engine::display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    if (game_manager != nullptr)
        game_manager->draw();

    glutSwapBuffers();
}

void Engine::reshape(int w, int h)
{
    window_size.width = w;
    window_size.height = h;
    glViewport(0, 0, w, h);
}

Coordinates Engine::Coordinates_to_vp(Coordinates point)
{
    Coordinates vp_point(0, 0);
    Size window = Engine::get_window_size_callback();

    vp_point.x = (point.x / (window.width / 2)) - 1;
    vp_point.y = (point.y / (window.height / 2)) - 1;
    return vp_point;
}
