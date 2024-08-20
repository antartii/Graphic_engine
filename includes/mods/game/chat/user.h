#ifndef GAME_USER
    #define GAME_USER

    #include "chat_message.h"

    #include <vector>
    #include <iostream>

class User {
    private :
        std::string username = "user";
        unsigned int id = 0;
        std::vector<Chat_message> chat_messages_sent;
        std::vector<Chat_message> chat_messages_received;

    public :
        User() {}
        User(std::string username, unsigned int id): id(id), username(username) {}

        std::string get_username(void) {return username;}
        void receive_chat_message(Chat_message chat_message) {chat_messages_received.push_back(chat_message);}
        void send_chat_message(Chat_message Chat_message) {chat_messages_sent.push_back(Chat_message);}
        std::vector<Chat_message> get_chat() {return chat_messages_received;}
        unsigned int get_id() {return id;}
};

#endif