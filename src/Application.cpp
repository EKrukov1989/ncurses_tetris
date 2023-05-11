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
    queue_ = std::make_unique<EventQueue>();
    controller_ = std::make_unique<Controller>(*queue_);
    view_ = std::make_unique<View>();
    model_ = std::make_unique<Model>(*view_, *queue_);
}

Application::~Application()
{
    endwin();
}

ApplicationError Application::run()
{
    if ( !view_->init() )
        return ApplicationError::NOCOLORS;

    model_->start();

    controller_->start();

    while(true)
    {
        auto ev_info = queue_->wait_and_get_event();

        if (ev_info.event == Event::STOP)
            break;

        model_->process_event(ev_info);
    }
    return ApplicationError::FINISHED_SUCCESSFULLY;
}

} // namespace Tetris
