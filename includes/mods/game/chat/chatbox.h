#ifndef GAME_CHATBOX
    #define GAME_CHATBOX

#include <map>
#include <iostream>
#include <vector>
#include "user.h"
#include "server.h"
#include "chat.h"

class Chatbox {
    private :
        User user;
        std::vector<Chat_message> messages;
        std::vector<User> users;
        std::vector<Text> texts;
        Server *server;
        Coordinates starting_coords;

        Size size;

    public :
        Chatbox() {};
        Chatbox(Server *server, Coordinates starting_coords, User user): server(server), starting_coords(starting_coords), user(user) {}

        void update_messages();
        void draw();
};

#endif