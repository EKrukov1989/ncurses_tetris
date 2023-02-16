#include "SmallScreenView.h"
#include <ncurses.h>
#include <string>

namespace
{

const std::vector<std::string> text = { "WINDOW TOO SMALL" };

}  // nameless namespace

namespace Tetris
{

bool SmallScreenView::show()
{
    OptionScreenView::show(text);
    return true;  // anyway
}

}  // namespace Tetris
