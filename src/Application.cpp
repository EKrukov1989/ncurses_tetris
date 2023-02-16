#include "Application.h"
#include "Views/View.h"
#include "Models/Model.h"
#include "Controller.h"
#include "EventQueue.h"
#include "Enums.h"
#include <chrono>
#include <ncurses.h>

namespace Tetris
{

Application::Application()
{
    initscr();
    auto queue_ = std::make_unique<EventQueue>();
    auto controller_ = std::make_unique<Controller>(*queue_);
    auto view_ = std::make_unique<View>();
    auto model_ = std::make_unique<Model>(*view_, *queue_);
}

Application::~Application()
{
    endwin();
}

void Application::run()
{
    model_->start();

    controller_->start();

    while(true)
    {
        auto ev_info = queue_->wait_and_get_event();

        if (ev_info.event == Event::STOP)
            break;

        model_->process_event(ev_info);
    }
}

} // namespace Tetris
