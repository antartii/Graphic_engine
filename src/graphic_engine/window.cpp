#include "window.h"

void Window::start(void)
{
    glutInitDisplayMode(display_mode);
    glutInitWindowSize(height, width);
    glutCreateWindow(title.c_str());
    status == STATUS::READY;
}