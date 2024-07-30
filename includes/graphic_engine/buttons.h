#ifndef BUTTON
    #define BUTTON

    #include "shapes2D.h"
    #include "colors.h"

    #include <GL/freeglut.h>
    #include <map>
    #include <vector>

enum class BUTTON_STATUS {
    HOVERED,
    UNHOVERED,
    CLICKED,
    UNCLICKED
};

class Button
{
    private:
        Shapes2D::Quad area = Shapes2D::Quad();
        GLboolean clicked = false;
        GLboolean hovered = false;
        GLboolean visible = false;
        Color color = Color::red();

        
        void (*hovered_function)(void) = nullptr;
        void (*unhovered_function)(void) = nullptr;
        void (*clicked_function)(void) = nullptr;
        void (*unclicked_function)(void) = nullptr;

    public :
        Button() {}
        Button(Shapes2D::Quad area): area(area) {}

        Shapes2D::Quad get_area(void) {return area;}
        Color get_color(void) {return color;}
        GLboolean get_visibility(void) {return visible;}

        void set_visibility(GLboolean visibility) {visible = visibility;}
        void set_color(Color color) {this->color = color;}
        void set_function(void (*function)(), BUTTON_STATUS button_status);

        void update_state(Shapes2D::Coord2D mousepos, GLboolean is_clicking);

        static std::map<std::string, Button> extract_from_table(std::vector<std::vector<std::string>> extracted_objects, std::map<std::string, Shapes2D::Coord2D> points);
};

#endif