#ifndef GAME_MANAGER
#define GAME_MANAGER


#include <iostream>
#include <cstdlib>
#include <map>

#include "engine.h"
#include "shapes_2D.h"
#include "text.h"

// Chat includes
#include "user.h"
#include "chat.h"
#include "server.h"
#include "chatbox.h"

class Engine;

// GAME 

class Current_streamer
{
    private :
        unsigned int id;
        User info;
        Text *username_display;

    public :
        Current_streamer(){}
        Current_streamer(unsigned int id, Server *server)
        {
            this->id = id;
            info = server->get_user(id);
            username_display = Text_storage::create_text(info.get_username(), Coordinates(150, 150));
        }
        void move_username_display(Coordinates new_coords) {username_display->change_coord(new_coords);}
        void display_username() {username_display->draw();}
        unsigned int get_id(void) {return id;}
        User get_infos(void) {return info;}

};

// END

class Game_manager {
    private:
        static Game_manager *instance;
        Engine *engine;

        // GAME CODE STARTING HERE
        Current_streamer current_streamer;

        // [test]
        unsigned int chatter_test;
        // [end test]

        Server server;

        // --- chatbox
        Chatbox chatbox;
        float chat_interval = 1;
        float next_chat_timer = 0;

        // GAME CODE ENDING HERE

    public:
        Game_manager() {};
        Game_manager(Engine *engine) : engine(engine) {};

        void init();
        void update();
        void draw();

        static void set_instance(Game_manager *game_manager) {instance = game_manager;}
        static void init_callback() {instance->init();}
        static void update_callback(int, int) {instance->update();}
        static void draw_callback() {instance->draw();}
};

#endif