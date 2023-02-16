#include "Model.h"
#include "Views/View.h"
#include "EventQueue.h"
#include "StartScreenModel.h"

namespace Tetris
{

Model::Model(View& v, EventQueue& eq)
    : view_(v)
    , queue_(eq)
{
    screen_models_.insert( { Screen::START_SCREEN, std::make_unique<StartScreenModel>() } );
    // ... other screen models

    current_screen_ = Screen::START_SCREEN;
}

void Model::start()
{
    const bool success = update_view_();
    if (!success)
        switch_screen_(Screen::SMALL_SCREEN);
}

void Model::switch_screen_(Tetris::Screen next_screen)
{
    screen_models_[current_screen_]->stop();
    current_screen_ = next_screen;
    screen_models_[current_screen_]->start();    
}

bool Model::update_view_()
{
    // return false if window size is too small

    switch (current_screen_)
    {
        case Screen::START_SCREEN:
            const auto& ref = *screen_models_[current_screen_];
            auto opt = dynamic_cast<const StartScreenModel&>(ref).get_state();
            return view_.show_start_screen(opt);
    }
    return true;  // normally never
}

void Model::process_event(const EventInfo& ev_info)
{   
    if (ev_info.event != Event::RESIZE)
    {
        const auto next_screen = screen_models_[current_screen_]->process_event(ev_info);
        if ( next_screen != current_screen_ )
            switch_screen_(next_screen);
    }

    const bool success = update_view_();
    if (!success)
        switch_screen_(Screen::SMALL_SCREEN);
}

} // namespace Tetris
