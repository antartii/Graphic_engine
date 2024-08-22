#include "chatbox.h"

void Chatbox::add_message(Chat_message message)
{
    messages.push_back(message);
    texts.push_back(Text(message.get_message(), Coordinates(starting_coords.x + messages.size() * 18 * 1.33, starting_coords.y)));
}

void Chatbox::update_messages()
{
    std::vector<Chat_message> new_chat_messages;
    int font_height = 18 * 1.33;

    new_chat_messages = messages.size() != 0 ? server->get_chat_from_stamp(messages.back().get_id()) : server->get_chat(user.get_id());
    if (new_chat_messages.size() != 0) {
        for (int i = 0; i < new_chat_messages.size(); i += 1) {
            messages.push_back(new_chat_messages[i]);
            texts.push_back(Text(new_chat_messages[i].get_message(), Coordinates(starting_coords.x, starting_coords.y + font_height * messages.size())));
        }
    }
}

void Chatbox::draw()
{
    for (int i = 0; i < texts.size(); i += 1)
        texts[i].draw();
}