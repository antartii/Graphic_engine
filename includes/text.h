#ifndef TEXT
    #define TEXT

#include "utils.h"
#include "engine.h"
#include <sstream>
#include <string>

#define FONT_HEIGHT 18 * 1.33

class Text {
    private :
        std::string content = "";
        std::vector<std::string> content_lines;
        int content_size = 0;
        Coordinates coords;
        std::vector<Coordinates> vp_coords;
        void *font = GLUT_BITMAP_HELVETICA_18;
        float height;

    public :
        Text() {};
        Text(std::string content, Coordinates coords);

        float get_height() {return height;}
        std::string get_content() {return content;}
        void set_font(void *font) {this->font = font;}
        void change_coord(Coordinates coords);
        void translate_coord(Coordinates coords);
        void draw();

        void update_vp();
        static void draw_line(std::string str, void *font, Coordinates vp_coordinates);
};

#endif