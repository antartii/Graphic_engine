#include "buttons.h"

std::map<std::string, Button> Button::extract_from_table(std::vector<std::vector<std::string>> table, std::map<std::string, Shapes2D::Coord2D> points) {
    std::map<std::string, Button> buttons;
    GLboolean is_reading = false;
    Shapes2D::Coord2D quad_points[4];

    for (size_t i = 0; i < table.size(); i += 1) {
        if (table[i].size() == 1)
            table[i][0] == "BUTTONS" ? is_reading = true : is_reading = false;
        else if (is_reading && table[i].size() >= 4) {
            for (int j = 0; j < 4; j += 1)
                quad_points[j] = points[table[i][j + 1]];
            buttons.insert({table[i][0], Button(Shapes2D::Quad(quad_points))});
        }
    }
    return buttons;
}

void Button::set_function(void (*function)(), BUTTON_STATUS button_status)
{
    switch (button_status) {
    case BUTTON_STATUS::HOVERED:
        this->hovered_function = function;
        break;
    case BUTTON_STATUS::CLICKED:
        this->clicked_function = function;
        break;
    case BUTTON_STATUS::UNCLICKED:
        this->unclicked_function = function;
        break;
    case BUTTON_STATUS::UNHOVERED:
        this->unhovered_function = function;
        break;
    default:
        break;
    }
}

void Button::update_state(Shapes2D::Coord2D mousepos, GLboolean is_clicking)
{
    GLboolean new_hovered = Shapes2D::is_contained(area.get_lines(), mousepos);

    if (!hovered && new_hovered && hovered_function)
        hovered_function();
    else if (hovered && !new_hovered && hovered_function)
        unhovered_function();
    hovered = new_hovered;
    if (hovered) {
        if (!clicked && is_clicking && clicked_function)
                clicked_function();
        else if (clicked && !is_clicking && unclicked_function)
            unclicked_function();
    }
    hovered ? clicked = is_clicking : clicked = false;
}
