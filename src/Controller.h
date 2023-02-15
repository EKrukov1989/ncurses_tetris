#pragma once

namespace Tetris
{
class EventQueue;

class Controller
{
public:
    Controller(EventQueue&);
    void start();
    
private:
    unsigned cols_ = 0;
    unsigned lines_ = 0;
    EventQueue& queue_;

    void check_resize_();
};

} // namespace Tetris