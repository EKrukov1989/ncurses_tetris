#pragma once
#include "OptionScreenView.h"
#include "Enums.h"

namespace Tetris
{
class View;

class StartScreenView : private OptionScreenView
{
    friend class View;
private:
    static void show(StartScreenOption option);
};

}  // namespace Tetris
