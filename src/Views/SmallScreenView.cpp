#include "SmallScreenView.h"
#include <ncurses.h>
#include <string>

namespace
{

const std::vector<std::string> text = { "WINDOW TOO SMALL" };

}  // nameless namespace

namespace Tetris
{

void SmallScreenView::show()
{
    OptionScreenView::show(text);
}

}  // namespace Tetris
