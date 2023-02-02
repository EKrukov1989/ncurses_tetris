#pragma once
#include "OptionScreenView.h"

namespace Tetris
{
class View;

class StartScreenView : private OptionScreenView
{
    friend class View;
public:
    enum class Option
    {
        START,
        CUSTOM,
        HELP,
        QUIT
    };
private:
    static void show(Option option);
};

}  // namespace Tetris
