#pragma once
#include "Enums.h"
#include <chrono>

namespace Tetris
{

struct EventInfo
{
    Event event;
    std::chrono::_V2::system_clock::time_point time;
};

}  // namespace Tetris
