#include "utils.h"

Coordinates Coordinates::operator+=(Coordinates coord)
{
    x += coord.x;
    y += coord.y;
    z += coord.z;
    return *this;
}

Coordinates Coordinates::operator-=(Coordinates coord)
{
    x -= coord.x;
    y -= coord.y;
    z -= coord.z;
    return *this;
}

Color Color::from_hexa(std::string hexcolor)
{
    int index = 0;
    Color color;

    if (hexcolor.size() != 6)
        return Color();
    color.r = char_to_hex(hexcolor[0]) * 16 + char_to_hex(hexcolor[1]);
    color.g = char_to_hex(hexcolor[2]) * 16 + char_to_hex(hexcolor[3]);
    color.b = char_to_hex(hexcolor[4]) * 16 + char_to_hex(hexcolor[5]);
    return color;
}

Color Color::to_ratio()
{
    Color ratio_color;

    ratio_color.r = r / 255.0f;
    ratio_color.g = g / 255.0f;
    ratio_color.b = b / 255.0f;
    return ratio_color;
}

unsigned int char_to_hex(char c) {return c - '0';}
float get_frame_duration(unsigned int fps) {return 1.0f / fps;}