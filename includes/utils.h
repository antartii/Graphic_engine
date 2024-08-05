#ifndef UTILS
    #define UTILS

class Color {
    public :
        float r = 0;
        float g = 0;
        float b = 0;
    
        Color(){};
        Color(float r, float g, float b): r(r), g(g), b(b) {}
        
        static Color red(){return Color(1, 0, 0);}
        static Color green(){return Color(0, 1, 0);}
        static Color blue(){return Color(0, 0, 1);}
};

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

class Line {
    public :
        Coordinates points[2] = {Coordinates(0, 0), Coordinates(0, 0)};

        Line(){}
        Line(Coordinates points[2]);
        Line(Coordinates starting_point, Coordinates vector);
};

#endif