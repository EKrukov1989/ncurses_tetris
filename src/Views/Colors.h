#pragma once

namespace Tetris
{

enum class InterfaceColor
{
    DIALOG_SCREEN = 1,
    DIALOG_SCREEN_CHOSEN,
    LAST
};

enum class TetrisColor
{
    TRANSPARENT = int(InterfaceColor::LAST),
    BACKGROUND,
    FULL_LINE,
    FIGURE_1,
    FIGURE_2,
    FIGURE_3,
    FIGURE_4,
    LAST
};

}  // namespace Tetris
