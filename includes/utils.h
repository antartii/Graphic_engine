#ifndef UTILS
    #define UTILS

class Size {
    public:
        int width = 0;
        int height = 0;
        int depth = 0;

        Size() {};
        Size(int width, int height): width(width), height(height) {}
        Size(int width, int height, int depth): width(width), height(height), depth(depth) {}
};

class Coordinates {
    public :
        float x = 0;
        float y = 0;
        float z = 0;

        Coordinates() {}
        Coordinates(int x, int y): x(x), y(y) {}
        Coordinates(int x, int y, int z): x(x), y(y), z(z) {}
};

#endif