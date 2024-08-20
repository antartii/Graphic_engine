#include "server.h"

User *Server::create_user(std::string username)
{
    users.push_back(User(username, users.size() + 1));
    return &(users.back());
}

void Server::create_chat_message(unsigned int id_sender, unsigned int id_receiver, std::string chat_message)
{
    User *sender = get_user(id_sender);
    User *receiver = get_user(id_receiver);

    if (sender != nullptr && receiver != nullptr)
    {
        Chat_message new_message = Chat_message(id_sender, chat_message, id_receiver, chat_messages.size());
        sender->send_chat_message(new_message);
        receiver->receive_chat_message(new_message);
    }
}

std::vector<Chat_message> Server::get_chat(unsigned int id_streamer)
{
    User *streamer = get_user(id_streamer);

    if (streamer != nullptr)
        return streamer->get_chat();
    return {};
}

void Server::DEBUG_show_chat_message(Chat_message chat_message)
{
    User sender = *get_user(chat_message.get_sender_id());
    User receiver = *get_user(chat_message.get_receiver_id());

    std::cout << "[" << sender.get_username() << "] => [" << receiver.get_username() << "] : " << std::endl;
    std::cout << "\t" + chat_message.get_message() << std::endl;
}