#pragma once
#include <memory>

namespace Tetris
{
class View;
class Model;
class EventQueue;
class Controller;

class Application
{
    std::unique_ptr<EventQueue> queue_;
    std::unique_ptr<View> view_;
    std::unique_ptr<Model> model_;
    std::unique_ptr<Controller> controller_;

public:
    Application();
    ~Application();
    void run();
};

} // namespace Tetris
