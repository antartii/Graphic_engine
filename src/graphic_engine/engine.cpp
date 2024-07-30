#include "engine.h"

void Engine::set_window(Window *window)
{
    if (this->status >= STATUS::INITIALIZED && window->get_status() >= STATUS::INITIALIZED) {
        this->window = window;
        this->status = STATUS::READY;
    }
}

void Engine::set_main_functions(void (*display)(), void (*idle)(), void (*reshape)(int, int))
{
    glutIdleFunc(idle);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
}

void Engine::set_mouse_functions(void (*mouse)(int button, int state, int x, int y), void (*motion)(int x, int y), void (*passive_motion)(int x, int y), void (*mouse_entry)(int state))
{
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutPassiveMotionFunc(motion);
    glutEntryFunc(mouse_entry);
}

void Engine::set_keyboard_functions(void (*keyboard_pressed)(unsigned char key, int x, int y), void (*keyboard_up)(unsigned char key, int x, int y))
{
    glutKeyboardFunc(keyboard_pressed);
    glutKeyboardUpFunc(keyboard_up);
}

void Engine::init()
{
    set_objects_path("assets/data/objects.uat");
    import_objects();
}

void Engine::update()
{
    Shapes2D::Coord2D mousepos = get_mousepos();

    for (auto &pair : this->buttons)
        if (is_mouse_in_window)
            pair.second.update_state(mousepos, is_key_active(SPECIAL_KEYS::MOUSE_LEFT_BUTTON));
}

void Engine::display()
{
    for (auto &pair : this->buttons) {
        if (pair.second.get_visibility()) {
            draw(pair.second.get_area(), pair.second.get_color());
        }
    }
}

void Engine::draw(Shapes2D::Coord2D pixel, Color color)
{
    GLfloat viewport_x = screen_coord_to_viewport(pixel.x, window->get_width());
    GLfloat viewport_y = screen_coord_to_viewport(pixel.y, window->get_height());

    glColor3f(color.r, color.g, color.b);
    glBegin(GL_POINTS);
    glVertex2d(viewport_x, viewport_y);
    glEnd();
}

void Engine::draw(Shapes2D::Quad quad, Color color)
{
    Shapes2D::Coord2D bottom_left = quad.get_point(DIRECTION::BOTTOM_LEFT);
    Shapes2D::Coord2D top_right = quad.get_point(DIRECTION::TOP_RIGHT);

    GLfloat start_viewport_x = screen_coord_to_viewport(bottom_left.x, window->get_width());
    GLfloat start_viewport_y = screen_coord_to_viewport(bottom_left.y, window->get_height());
    GLfloat end_viewport_x = screen_coord_to_viewport(top_right.x, window->get_width());
    GLfloat end_viewport_y = screen_coord_to_viewport(top_right.y, window->get_height());

    glColor3f(color.r, color.g, color.b);
    glBegin(GL_QUADS);
    glVertex2d(start_viewport_x, start_viewport_y);
    glVertex2d(start_viewport_x, end_viewport_y);
    glVertex2d(end_viewport_x, end_viewport_y);
    glVertex2d(end_viewport_x, start_viewport_y);
    glEnd();
}

void Engine::draw_viewport(Shapes2D::Coord2D pixel, Color color)
{
    glColor3f(color.r, color.g, color.b);
    glBegin(GL_POINTS);
    glVertex2d(0, 0);
    glEnd();
}

void Engine::draw_viewport(Shapes2D::Quad quad, Color color)
{
    Shapes2D::Coord2D bottom_left = quad.get_point(DIRECTION::BOTTOM_LEFT);
    Shapes2D::Coord2D top_right = quad.get_point(DIRECTION::TOP_RIGHT);

    glColor3f(color.r, color.g, color.b);
    glBegin(GL_QUADS);
    glVertex2d(bottom_left.x, bottom_left.y);
    glVertex2d(bottom_left.x, top_right.y);
    glVertex2d(top_right.x, top_right.y);
    glVertex2d(top_right.x, bottom_left.y);
    glEnd();
}

void Engine::import_objects(void)
{
    std::string file_content = get_file_content(objects_path);
    std::vector<std::vector<std::string>> objects_data = Uat::string_to_table(file_content);

    buttons = Button::extract_from_uat(objects_data);
}

void Engine::add_active_key(unsigned char key)
{
    auto it = std::find(active_key.begin(), active_key.end(), key);

    if (it == active_key.end())
        active_key.push_back(key);
}

void Engine::release_active_key(unsigned char key)
{
    auto it = std::find(active_key.begin(), active_key.end(), key);

    if (it != active_key.end())
        active_key.erase(it);
}

GLboolean Engine::is_key_active(unsigned char key)
{
    auto it = std::find(active_key.begin(), active_key.end(), key);

    if (it != active_key.end())
        return true;
    return false;
}

void Engine::add_active_key(SPECIAL_KEYS key) {
    auto it = std::find(active_special_key.begin(), active_special_key.end(), key);

    if (it == active_special_key.end())
        active_special_key.push_back(key);
}

void Engine::release_active_key(SPECIAL_KEYS key) {
    auto it = std::find(active_special_key.begin(), active_special_key.end(), key);

    if (it != active_special_key.end())
        active_special_key.erase(it);
}

GLboolean Engine::is_key_active(SPECIAL_KEYS key) {
    auto it = std::find(active_special_key.begin(), active_special_key.end(), key);

    if (it != active_special_key.end())
        return true;
    return false;
}
