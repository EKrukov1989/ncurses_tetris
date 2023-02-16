#pragma once
#include "Enums.h"

namespace Tetris
{
struct EventInfo;

class IScreenModel
{
public:
    virtual ~IScreenModel() = default;

    // return next screen (it may be this screen or screen that must be started next)
    virtual Tetris::Screen process_event(const EventInfo&) = 0;
    virtual void start() {};
    virtual void stop() {};
};

}  // namespace Tetris