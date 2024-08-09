#include "mathematics.h"

long double Math::maximum(long double a, long double b) {return (a > b ? a : b);}
long double Math::minimum(long double a, long double b) {return (a > b ? b : a);}
long double Math::get_circle_circonference(long double radius) {return 2.0L * PI * radius;}
long double Math::abs(long double x) {return (x < 0 ? x * -1L: x);}
long double Math::distance(Coordinates p1, Coordinates p2) {return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));}
long double Math::binomial_coef(long double n, long double k) {return (n < k ? 0 : factorial(n) / (factorial(k) * factorial(n - k)));}

long double Math::pow(long double x, int power)
{
    long double result = 1;

    if (x == 0)
        return 0;
    if (power == 0)
        return 1;
    for (int i = 0; i < power; i += 1)
        result *= x;
    return result;
}

long double Math::factorial(long double x)
{
    long double result = x;

    if (x == 0)
        return 1;
    for (int i = x - 1; i > 0; i -= 1)
        result *= i;
    return result;
}

long double Math::cos(long double x)
{
    long double sum = 0;
    long double prev_sum = sum;

    if (x == 0)
        return 1;
    for (int i = 0; abs(sum - prev_sum) > LONG_DOUBLE_THRESHOLD || i == 0; i += 1) {
        prev_sum = sum;
        sum += (pow(-1, i) / factorial(2 * i)) * pow(x, 2 * i);
    }
    return sum;
}

long double Math::sin(long double x)
{
    long double sum = 0;
    long double prev_sum = sum;

    if (x == 0)
        return 0;
    for (int i = 0; abs(sum - prev_sum) > LONG_DOUBLE_THRESHOLD || i == 0; i += 1) {
        prev_sum = sum;
        sum += pow(-1, i) * (pow(x, 2 * i + 1) / factorial(2 * i + 1));
    }
    return sum;
}

long double Math::sum(std::vector<long double> numbers)
{
    int array_size = numbers.size();
    long double sum = 0;

    for (int i = 0; i < array_size; i += 1)
        sum += numbers[i];
    return sum;
}

Coordinates Math::apply_rotation(Coordinates origin, long double angle)
{
    long double x = origin.x * Math::cos(angle) - origin.y * Math::sin(angle);
    long double y = origin.x * Math::sin(angle) - origin.y * Math::cos(angle);

    return Coordinates(x, y);
}

long double Math::sqrt(long double x)
{

    long double sum = x;
    long double prev_sum = 0;

    if (x == 0 || x == 1)
        return x;
    if (x < 0)
        return 0;
    for (int i = 0; abs(sum - prev_sum) > LONG_DOUBLE_THRESHOLD; i += 1) {
        prev_sum = sum;
        sum += x / sum;
        sum /=  2.0f;
    }
    return sum;
}