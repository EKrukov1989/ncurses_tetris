#pragma once
#include "OptionScreenView.h"

namespace Tetris
{
class View;

class SmallScreenView : private OptionScreenView
{
    friend class View;
private:
    static void show();
};

}  // namespace Tetris
