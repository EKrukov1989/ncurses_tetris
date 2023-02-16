#include "PauseScreenView.h"
#include <ncurses.h>
#include "View.h"

namespace
{

// Content and order of strings in next array must correspond with enum in the header!
const std::vector<std::string> opts = { " resume  ",
                                        " abandon " };

}  // nameless namespace

namespace Tetris
{

bool PauseScreenView::show(Option option)
{
    return OptionScreenView::show(opts, int(option));
}

}  // namespace Tetris
