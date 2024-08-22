#ifndef TEXT
    #define TEXT

#include "utils.h"
#include "engine.h"

class Text {
    private :
        std::string content = "";
        int content_size = 0;
        Coordinates coords;
        Coordinates vp_coords;
        void *font = GLUT_BITMAP_HELVETICA_18;

    public :
        Text() {};
        Text(std::string content, Coordinates coords);

        void set_font(void *font) {this->font = font;}
        void draw();
};

#endif