#include "PauseScreenView.h"
#include <ncurses.h>
#include "View.h"

namespace
{

// Content and order of strings in next array must correspond with enum!
const std::vector<std::string> opts = { " resume  ",
                                        " abandon " };

}  // nameless namespace

namespace Tetris
{

void PauseScreenView::show(Option option)
{
    OptionScreenView::show(opts, int(option));
}

}  // namespace Tetris
