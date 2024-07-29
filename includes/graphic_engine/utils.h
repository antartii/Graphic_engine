#ifndef UTILS
#define UTILS

#include <GL/freeglut.h>
#include <iostream>
#include <fstream>

enum class STATUS
{
    NOT_INITIALIZED = 0,
    INITIALIZED,
    READY,
    ACTIVE
};

enum class DIRECTION
{
    TOP = 0,
    TOP_LEFT,
    LEFT,
    BOTTOM_LEFT,
    BOTTOM,
    BOTTOM_RIGHT,
    RIGHT,
    TOP_RIGHT,
};

GLfloat screen_coord_to_viewport(GLfloat coord, GLfloat size);

std::string get_file_content(std::string file_path);

#endif