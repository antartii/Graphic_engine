#include "chatbox.h"

void Chatbox::update_messages()
{
    std::vector<Chat_message> new_chat_messages;
    std::vector<Text> new_chat_messages_text;
    float total_new_height = 0;
    int previous_message_size = messages.size();

    new_chat_messages = messages.size() != 0 ? server->get_chat_from_stamp(messages.back().get_id()) : server->get_chat(user.get_id());
    if (new_chat_messages.size() != 0) {
        for (int i = 0; i < new_chat_messages.size(); i += 1) {
            messages.push_back(new_chat_messages[i]);
            new_chat_messages_text.push_back(Text("test\n"+ new_chat_messages[i].get_message(), Coordinates(starting_coords.x, starting_coords.y + total_new_height)));
            total_new_height += new_chat_messages_text[i].get_height();
        }
        for (int i = 0; i < previous_message_size; i += 1)
            texts[i].translate_coord(Coordinates(0, total_new_height));
        texts.insert(texts.end(), new_chat_messages_text.begin(), new_chat_messages_text.end());
    }
}

void Chatbox::draw()
{
    for (int i = 0; i < texts.size(); i += 1)
        texts[i].draw();
}