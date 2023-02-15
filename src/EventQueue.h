#pragma once
#include <chrono>
#include <condition_variable>
#include <mutex>
#include <queue>

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

private:
    mutable std::mutex m_;
    std::condition_variable cv_;
    std::queue<EventInfo> q_;
};

} // namespace Tetris