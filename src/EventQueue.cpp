#include "EventQueue.h"
#include "Enums.h"

namespace Tetris
{

EventQueue::EventQueue()
{
}

void EventQueue::push_event(Event e)
{
    std::lock_guard lg(m_);
    auto t = std::chrono::high_resolution_clock::now();
    EventInfo info = {e, t};
    q_.push(info);
    cv_.notify_all();
}

EventInfo EventQueue::wait_and_get_event()
{
    std::unique_lock<std::mutex> ulk(m_);
    cv_.wait(ulk, [this]{ return !q_.empty(); } );
    auto res = q_.front();
    q_.pop();
    return res;
}

} // namespace Tetris