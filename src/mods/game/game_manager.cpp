#include "game_manager.h"

void Game_manager::init(void)
{
    engine->set_window_title("Vtuber academy");
    engine->set_background(Color::from_hexa("0E0E10"));

    // TEST
    current_streamer = server.create_user("traveler_anta");
    test = server.create_user("law san");
    server.create_chat_message(test, current_streamer, "hello !");
    server.create_chat_message(test, current_streamer, "how's life today ?");
    server.create_chat_message(test, current_streamer, "yeah me too....");

    std::vector<Chat_message> messages = server.get_chat(current_streamer);
    for (int i = 0; i < messages.size(); i += 1)
        server.DEBUG_show_chat_message(messages[i]);
    // END TEST
}

void Game_manager::update(void)
{

}

void Game_manager::draw(void)
{

}
