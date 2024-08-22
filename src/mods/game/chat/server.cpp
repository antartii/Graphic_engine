#include "server.h"

int Server::get_chat_message_index(unsigned int id)
{
    for (int i = 0; i < chat_messages.size(); i += 1) {
        if (chat_messages[i].get_id() == id)
            return i;
    }
    return -1;
}

unsigned int Server::create_user(std::string username)
{
    users.push_back(User(username, users.size() + 1));
    return users.back().get_id();
}

void Server::create_chat_message(unsigned int id_sender, unsigned int id_receiver, std::string chat_message)
{
    User *sender = get_user_address(id_sender);
    User *receiver = get_user_address(id_receiver);

    if (sender && receiver)
    {
        Chat_message new_message = Chat_message(id_sender, chat_message, id_receiver, chat_messages.size());
        sender->send_chat_message(new_message);
        receiver->receive_chat_message(new_message);
        chat_messages.push_back(new_message);
    }
}

std::vector<Chat_message> Server::get_chat(unsigned int id_streamer)
{
    User streamer = get_user(id_streamer);

    if (streamer.get_id() != 0)
        return streamer.get_chat();
    return {};
}

void Server::DEBUG_show_chat_message(Chat_message chat_message)
{
    User sender = get_user(chat_message.get_sender_id());
    User receiver = get_user(chat_message.get_receiver_id());

    std::cout << "[" << sender.get_username() << "] => [" << receiver.get_username() << "] : " << std::endl;
    std::cout << "\t" + chat_message.get_message() << std::endl;
}

std::vector<Chat_message> Server::get_chat_from_stamp(unsigned int id_chat_message_stamp)
{
    int index = get_chat_message_index(id_chat_message_stamp);

    if (index != -1)
        return std::vector<Chat_message>(chat_messages.begin() + 1 + index, chat_messages.end());
    return {};
}