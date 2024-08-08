#ifndef MATH
#define MATH

#include "utils.h"

class Math
{
    public :
        static long double maximum(long double a, long double b);
        static long double minimum(long double a, long double b);
        static long double get_circle_circonference(long double radius);
        static long double get_circle_radian(long double radians);
        static long double pow(long double x, int power);
        static long double factorial(long double x);
        static long double cos(long double x);
        static long double abs(long double x);
        static long double sin(long double x);
        static long double sum(std::vector<long double> numbers);
        static long double average(std::vector<long double> numbers) {return sum(numbers) / (long double) numbers.size();}
        static long double deg_to_rad(long double deg) {return deg * PI / 180L;}
        static long double rad_to_deg(long double rad) {return rad * 180L / PI;}
        static Coordinates polar_coordinate(long double r, long double angle) {return Coordinates(r * Math::cos(angle), r * Math::sin(angle));}
        static Coordinates cartesian_coordinates(long double a, long double b, long double angle) {return Coordinates(a * Math::cos(angle), b * Math::sin(angle));}
        static Coordinates apply_rotation(Coordinates origin, long double angle);
};

#endif