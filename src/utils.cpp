#include "utils.h"

Coordinates Coordinates::operator+=(Coordinates coord)
{
    x += coord.x;
    y += coord.y;
    z += coord.z;
    return *this;
}
