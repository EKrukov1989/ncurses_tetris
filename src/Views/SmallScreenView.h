#pragma once
#include "OptionScreenView.h"

namespace Tetris
{
class View;

class SmallScreenView : private OptionScreenView
{
    friend class View;
private:
    static bool show();
};

}  // namespace Tetris
