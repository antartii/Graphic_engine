#include "buttons.h"

std::map<std::string, Button> Button::extract_from_uat(std::vector<std::vector<std::string>> extracted_objects)
{
    std::map<std::string, Button> buttons;
    GLboolean is_reading = false;
    GLfloat width;
    GLfloat height;
    Shapes2D::Coord2D start;
    Button new_button;

    for (size_t i = 0; i < extracted_objects.size(); i += 1) {
        if (extracted_objects[i].size() == 1) {
            if (extracted_objects[i][0] == "BUTTONS")
                is_reading = true;
            else
                is_reading = false;
        } else if (is_reading) {
            // for 2D buttons
            if (extracted_objects[i].size() == 8) {
                width = std::stof(extracted_objects[i][3]);
                height = std::stof(extracted_objects[i][4]);
                start = Shapes2D::Coord2D(std::stof(extracted_objects[i][1]), std::stof(extracted_objects[i][2]));

                new_button = Button(Shapes2D::Quad(start, width, height));
                new_button.set_color(Color::red());

                buttons.insert({extracted_objects[i][0], new_button});
            }

            // for 3D buttons (later update) or other buttons shape than quad
            /*
            if (extracted_objects[i].size() >= ???) {
                
            }
            */
        }
    } 
    return buttons;
}