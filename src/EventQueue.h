#pragma once
#include <chrono>


namespace Tetris
{
enum class Event;

class EventQueue
{
public:
    struct EventInfo
    {
        Event event;
        std::chrono::_V2::system_clock::time_point time;
    };

    EventQueue();

    void push_event(Event);
    EventInfo wait_and_get_event();
};

} // namespace Tetris