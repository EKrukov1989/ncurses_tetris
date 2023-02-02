#pragma once
#include "Enums.h"
#include "StartScreenView.h"

namespace Tetris
{

class View
{
    friend class StartScreenView;

    enum class InterfaceColor
    {
        DIALOG_SCREEN = 1,
        DIALOG_SCREEN_CHOSEN,
        LAST

    };

public:
    enum class TetrisColor
    {
        BACKGROUND = int(InterfaceColor::LAST),
        FULL_LINE,
        FIGURE_1,
        FIGURE_2,
        FIGURE_3,
        FIGURE_4
    };

    View();
    bool init();
    ~View();

    void show_start_screen(StartScreenView::Option);
};

}  // namespace Tetris