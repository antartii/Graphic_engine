#include "window.h"

void Window::start(void)
{
    glutInitDisplayMode(display_mode);
    glutInitWindowSize(height, width);
    glutInitWindowPosition(position.x, position.y);
    glutCreateWindow(title.c_str());
    status == STATUS::READY;
}

void Window::reshape(GLint width, GLint height)
{
    this->width = width;
    this->height = height;
    glutReshapeWindow(width, height);
}

void Window::toggle_fullscreen(void)
{
    resizing = true;
    if (!fullscreen) {
        std::cout << "full size : " << width << " , " << height << std::endl;
        glutFullScreen();
    } else {
        std::cout << "unfull size : " << width << " , " << height << std::endl;
        glutReshapeWindow(width, height);
        glutPositionWindow(0, 0);
    }
    fullscreen = !fullscreen;
    resizing = false;
}
