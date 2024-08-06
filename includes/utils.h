#ifndef UTILS
    #define UTILS

    #include <vector>
    #include <cmath>
    #include <GL/freeglut.h>

class Color {
    public :
        float r, g, b = 0;
    
        Color(){};
        Color(float r, float g, float b): r(r), g(g), b(b) {}
        
        static Color red(){return Color(1, 0, 0);}
        static Color green(){return Color(0, 1, 0);}
        static Color blue(){return Color(0, 0, 1);}
};

class Size {
    public:
        int width, height, depth = 0;

        Size() {};
        Size(int width, int height): width(width), height(height) {}
        Size(int width, int height, int depth): width(width), height(height), depth(depth) {}
};

class Coordinates {
    public :
        float x, y, z = 0;

        Coordinates() {}
        Coordinates(int x, int y): x(x), y(y) {}
        Coordinates(int x, int y, int z): x(x), y(y), z(z) {}

        static Coordinates coordinates_to_vp(Coordinates point, Size window);
        static void draw(Coordinates point, Color color, Size window);
};

/*class Circle {
    private :
        Coordinates center;
        float radius;
        int segments_count;
        std::vector<Coordinates> points;

    public :
        Circle(){}
        Circle(Coordinates center, float radius, int segments_count);

        float get_radius(void) {return radius;}
        int get_segments_count(void) {return segments_count;}
        Coordinates get_center(void) {return center;}
        std::vector<Coordinates> get_points(void) {return points;}
};*/

#endif