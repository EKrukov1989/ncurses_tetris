#include "EventQueue.h"
#include "Enums.h"

namespace Tetris
{

EventQueue::EventQueue()
{
}

void EventQueue::push_event(Event)
{
}

EventQueue::EventInfo EventQueue::wait_and_get_event()
{
    return {};
}

} // namespace Tetris