#pragma once
#include <condition_variable>
#include <mutex>
#include <queue>
#include "EventInfo.h"

namespace Tetris
{
enum class Event;

class EventQueue
{
public:
    EventQueue();

    void push_event(Event);
    EventInfo wait_and_get_event();

private:
    mutable std::mutex m_;
    std::condition_variable cv_;
    std::queue<EventInfo> q_;
};

} // namespace Tetris