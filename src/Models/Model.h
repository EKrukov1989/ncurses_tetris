#pragma once
#include "EventQueue.h"
#include <unordered_map>
#include <memory>
#include "IScreenModel.h"

namespace Tetris
{
class View;

class Model
{
public:
    Model(View&, EventQueue&);
    void process_event(const EventInfo&);
    void start();

private:
    Tetris::Screen current_screen_ = Tetris::Screen::INVALID;
    std::unordered_map<Tetris::Screen, std::unique_ptr<IScreenModel>> screen_models_; 
    View& view_;
    EventQueue& queue_;

    bool update_view_();
    void switch_screen_(Tetris::Screen next_screen);
};

} // namespace Tetris
