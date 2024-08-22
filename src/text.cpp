#include "text.h"

Text::Text(std::string content, Coordinates coords)
{
    this->coords = coords;
    vp_coords = Engine::coordinates_to_vp(coords);
    this->content = content;
    content_size = content.size();
}

void Text::draw() {
    glRasterPos2f(vp_coords.x, vp_coords.y);
    for (int i = 0; i < content_size; i += 1)
    glutBitmapCharacter(font, content[i]);
}
