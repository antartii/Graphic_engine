#include "text.h"

std::vector<std::string> str_split_line(std::string str)
{
    std::vector<std::string> splited_str = {str};
    std::istringstream stream(str);
    std::string temp;

    while (std::getline(stream, temp))
        splited_str.push_back(temp);
    return splited_str;
}

Text::Text(std::string content, Coordinates coords)
{
    this->coords = coords;
    this->content = content;
    this->content_lines = str_split_line(content);
    update_vp();
    height = FONT_HEIGHT * content_lines.size();
    content_size = content.size();
}

void Text::update_vp()
{
    vp_coords.clear();
    for (int i = content_lines.size() - 1; i >= 0; i -= 1)
        vp_coords.push_back(Engine::coordinates_to_vp(coords + Coordinates(0, i * FONT_HEIGHT)));
}

void Text::draw() {
    for (int i = 0; i < content_lines.size(); i += 1)
        Text::draw_line(content_lines[i], font, vp_coords[i]);
}

void Text::draw_line(std::string str, void *font, Coordinates vp_coords)
{
    glRasterPos2f(vp_coords.x, vp_coords.y);
    std::cout << str << " : " << vp_coords.x << " : " << vp_coords.y << std::endl;
    for (int j = 0; j < str.size(); j += 1)
        glutBitmapCharacter(font, str[j]);
}

void Text::change_coord(Coordinates coords)
{
    this->coords = coords;
    update_vp();
}

void Text::translate_coord(Coordinates coords)
{
    this->coords += coords;
    std::cout << "ok ?" << std::endl;
    update_vp();
}