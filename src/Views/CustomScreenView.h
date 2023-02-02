#pragma once
#include "OptionScreenView.h"

namespace Tetris
{
class View;

class CustomScreenView : private OptionScreenView
{
    friend class View;
public:
    struct Settings
    {
        unsigned speed  = 0;
        unsigned height = 0;
        unsigned width  = 0;
    };

    enum class Option
    {
        START_CUSTOM_GAME,
        SPEED,
        HEIGHT,
        WIDTH,
        BACK
    };
private:
    static void show(Option, Settings);
};

}  // namespace Tetris
