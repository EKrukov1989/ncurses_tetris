#pragma once
#include "OptionScreenView.h"

namespace Tetris
{
class View;

class PauseScreenView : private OptionScreenView
{
    friend class View;
public:
    enum class Option
    {
        RESUME,
        ABANDON
    };
private:
    static bool show(Option option);
};

}  // namespace Tetris
