#pragma once
#include "EventQueue.h"

namespace Tetris
{
class View;

class Model
{
    View& view_;
    EventQueue& queue_;
public:
    Model(View&, EventQueue&);
    void process_event(EventQueue::EventInfo);
};

} // namespace Tetris
