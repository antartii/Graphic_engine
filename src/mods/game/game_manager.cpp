#include "game_manager.h"

void Game_manager::init(void)
{
    engine->set_window_title("Vtuber academy");
    engine->set_background(Color::from_hexa("0E0E10").to_ratio());

    // TEST
    current_streamer = server.create_user("traveler_anta");
    test = server.create_user("law san");
    server.create_chat_message(test->get_id(), current_streamer->get_id(), "hello !");
    server.create_chat_message(test->get_id(), current_streamer->get_id(), "how's life today ?");
    server.create_chat_message(test->get_id(), current_streamer->get_id(), "yeah me too....");

    std::vector<Chat_message> messages = server.get_chat(current_streamer->get_id());
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
