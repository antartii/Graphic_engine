#include "game_manager.h"

void Game_manager::init(void)
{
    engine->set_window_title("Vtuber academy");
    engine->set_background(Color::from_hexa("0E0E10"));
    engine->set_window_size(Size(300, 300));

    current_streamer = Current_streamer(server.create_user("traveler_anta"), &server);
    //current_streamer.move_username_display(Coordinates(150, 50));

    chatter_test = server.create_user("law san");

    chatbox = Chatbox(&server, Coordinates(1500, 200), current_streamer.get_infos());
    server.create_chat_message(chatter_test, current_streamer.get_id(), "hello !");
    server.create_chat_message(chatter_test, current_streamer.get_id(), "how's life \ntoday ?");
    server.create_chat_message(chatter_test, current_streamer.get_id(), "yeah me too....");
    next_chat_timer = engine->get_timer();

    // DEBUG
    std::vector<Chat_message> messages = server.get_chat(current_streamer.get_id());
    for (int i = 0; i < messages.size(); i += 1)
        server.DEBUG_show_chat_message(messages[i]);
}

void Game_manager::update(void)
{
    float current_timer = engine->get_timer();
    
    if (next_chat_timer <= current_timer) {
        next_chat_timer += chat_interval;
        server.create_chat_message(chatter_test, current_streamer.get_id(), "yeah \nme too....");
        server.create_chat_message(chatter_test, current_streamer.get_id(), "clip it guys");
        std::vector<Chat_message> messages = server.get_chat(current_streamer.get_id());
        for (int i = 0; i < messages.size(); i += 1)
            server.DEBUG_show_chat_message(messages[i]);
    }
    chatbox.update_messages();
}

void Game_manager::draw(void)
{
    current_streamer.display_username();
    chatbox.draw();
}
