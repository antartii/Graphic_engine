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
        std::map<int, std::string> usernames;
        std::vector<Text> texts;
        Server *server;
        Coordinates starting_coords;

    public :
        Chatbox() {};
        Chatbox(Server *server, Coordinates starting_coords, User user): server(server), starting_coords(starting_coords), user(user) {}

        void add_message(Chat_message message);
        void update_messages();
        void draw();
};

#endif