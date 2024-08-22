#include "game_manager.h"

void Game_manager::init(void)
{
    engine->set_window_title("Vtuber academy");
    engine->set_background(Color::from_hexa("0E0E10"));
    engine->set_window_size(Size(300, 300));

    current_streamer = server.create_user("traveler_anta");
    chatter_test = server.create_user("law san");
    server.create_chat_message(chatter_test, current_streamer, "hello !");
    server.create_chat_message(chatter_test, current_streamer, "how's life \ntoday ?");
    server.create_chat_message(chatter_test, current_streamer, "yeah me too....");

    next_chat_timer = engine->get_timer();

    chatbox = Chatbox(&server, Coordinates(150, 150), server.get_user(current_streamer));
    std::cout << server.get_user(current_streamer).get_username() << std::endl;

    // DEBUG
    std::vector<Chat_message> messages = server.get_chat(current_streamer);
    for (int i = 0; i < messages.size(); i += 1)
        server.DEBUG_show_chat_message(messages[i]);
}

void Game_manager::update(void)
{
    float current_timer = engine->get_timer();
    
    if (next_chat_timer <= current_timer) {
        next_chat_timer += chat_interval;
        std::cout << std::endl << std::endl;
        server.create_chat_message(chatter_test, current_streamer, "yeah \nme too....");
        server.create_chat_message(chatter_test, current_streamer, "clip it guys");
        std::vector<Chat_message> messages = server.get_chat(current_streamer);
        for (int i = 0; i < messages.size(); i += 1)
            server.DEBUG_show_chat_message(messages[i]);
    }

    chatbox.update_messages();
}

void Game_manager::draw(void)
{
    chatbox.draw();
}
