#include "Controller.h"
#include "EventQueue.h"
#include "Enums.h"
#include <thread>
#include <chrono>
#include <ncurses.h>
#include <iostream>

namespace
{

Tetris::Event s_map_event(int ch)
{
    switch(ch)
    {
        case KEY_UP:    return Tetris::Event::UP;
        case KEY_DOWN:  return Tetris::Event::DOWN;
        case KEY_LEFT:  return Tetris::Event::LEFT;
        case KEY_RIGHT: return Tetris::Event::RIGHT;
        case KEY_F(1):  return Tetris::Event::HELP;
        case 'h': return Tetris::Event::HELP;
        case ' ':  return Tetris::Event::ROTATE;
        case 'p': return Tetris::Event::PAUSE;
        case '\n':  return Tetris::Event::CONFIRM;
        case 'q':  return Tetris::Event::LEAVE;
        default:  return Tetris::Event::INVALID;
    }
}

}  // nameless namespace

namespace Tetris
{

Controller::Controller(EventQueue& eq) : queue_(eq)
{
    noecho();
    keypad(stdscr,TRUE);
    getmaxyx(stdscr, lines_, cols_);
    nodelay(stdscr,TRUE);
}

void Controller::check_resize_()
{
    if ( lines_ != LINES || cols_ != COLS )
    {
        lines_ = LINES;
        cols_ = COLS;
        queue_.push_event( Tetris::Event::RESIZE );
    }
}

void Controller::start()
{
    auto listen = [this]
    {
        while(true)
        {   
            check_resize_();

            int ch = getch();

            if (ch == ERR)
                continue;

            auto ev = s_map_event(ch);

            if (ev == Event::INVALID)
                continue;

            queue_.push_event( ev );
        }
    };

    std::thread controller_thread(listen);
    controller_thread.detach();
}

} // namespace Tetris