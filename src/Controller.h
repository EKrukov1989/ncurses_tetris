#pragma once

namespace Tetris
{
class EventQueue;

class Controller
{
    EventQueue& queue_;
public:
    Controller(EventQueue&);
    void start();
};

} // namespace Tetris