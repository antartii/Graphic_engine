#include "utils.h"

GLfloat screen_coord_to_viewport(GLfloat coord, GLfloat size)
{
    return 2.0 * (coord / size) - 1.0;
}

std::string get_file_content(std::string file_path) {
    std::string file_content = "";
    std::string file_line = "";
    std::ifstream file(file_path);

    if (!file.is_open())
        return "";
    while (getline(file, file_line))
        file_content += file_line + '\n';
    file.close();
    return file_content;
}