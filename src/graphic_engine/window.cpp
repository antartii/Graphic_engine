#include "window.h"

void Window::start(void)
{
    glutInitDisplayMode(display_mode);
    glutInitWindowSize(height, width);
    glutInitWindowPosition(position.x, position.y);
    glutCreateWindow(title.c_str());
    status == STATUS::READY;
}

void Window::reshape_window(GLint width, GLint height)
{
    this->width = width;
    this->height = height;
    glutReshapeWindow(width, height);
    glutPositionWindow(position.x, position.y);
}
