#ifndef GAME_SERVER
#define GAME_SERVER

#include "user.h"
#include <vector>

class Server {
    private:
        std::vector<Chat_message> chat_messages;
        std::vector<User> users;

    public:
        Server() {}

        User *get_user(unsigned int id) { return (id - 1 >= users.size() ? nullptr : &(users[id - 1])); }
        User *create_user(std::string username);
        void create_chat_message(unsigned int id_sender, unsigned int id_receiver, std::string chat_message);
        std::vector<Chat_message> get_chat(unsigned int id_streamer);

        void DEBUG_show_chat_message(Chat_message chat_message);
};

#endif