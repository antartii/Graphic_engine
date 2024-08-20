#include "utils.h"

Coordinates Coordinates::operator+=(Coordinates coord)
{
    x += coord.x;
    y += coord.y;
    z += coord.z;
    return *this;
}

Color Color::from_hexa(std::string hexcolor)
{
    int index = 0;
    Color color;

    if (hexcolor.size() != 6)
        return Color();
    color.r = hexcolor[0] * 16 + hexcolor[1];
    color.g = hexcolor[2] * 16 + hexcolor[3];
    color.b = hexcolor[4] * 16 + hexcolor[5];
    return color;
}
