#ifndef BUTTON
    #define BUTTON

    #include "shapes2D.h"
    #include "colors.h"

    #include <GL/freeglut.h>
    #include <map>
    #include <vector>

class Button
{
    private:
        Shapes2D::Quad area = Shapes2D::Quad();
        GLboolean clicked = false;
        GLboolean hovered = false;
        GLboolean visible = false;
        Color color = Color::red();

    public :
        Button() {}
        Button(Shapes2D::Quad area): area(area) {}

        Shapes2D::Quad get_area(void) {return area;}

        void set_visibility(GLboolean visibility) {visible = visibility;}
        void set_color(Color color) {this->color = color;}
        
        Color get_color(void) {return color;}
        
        GLboolean get_visibility(void) {return visible;}
        
        void update_state(Shapes2D::Coord2D mousepos, GLboolean is_clicking) {area.is_contained(mousepos)? hovered = true : hovered = false;}

    // TODO make it able to be any shape
    // TODO check mouse hovering & clicking

        static std::map<std::string, Button> extract_from_uat(std::vector<std::vector<std::string>> extracted_objects);
};

#endif