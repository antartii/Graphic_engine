#ifndef GAME_CHAT
    #define GAME_CHAT

    #include <iostream>
    #include "text.h"
    #include <map>

class Chat_message {
    private :
        unsigned int id_sender = 0;
        std::string message = "hey !";
        unsigned int id = 0;
        unsigned int id_receiver = 0;

    public :
        Chat_message() {}
        Chat_message(unsigned int id_sender, std::string message, unsigned int id_receiver, unsigned int id): id_sender(id_sender), message(message), id_receiver(id_receiver), id(id) {}

        unsigned int get_id() {return id;}
        unsigned int get_sender_id() {return id_sender;}
        unsigned int get_receiver_id() {return id_receiver;}
        std::string get_message() {return message;}
};

#endif