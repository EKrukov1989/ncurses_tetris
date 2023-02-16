#include "StartScreenView.h"
#include <ncurses.h>
#include "View.h"

namespace
{

// Content and order of strings in next array must correspond with enum in the header!
const std::vector<std::string> opts = { " start  ",
                                        " custom ",
                                        "  help  ",
                                        "  quit  " };

}  // nameless namespace

namespace Tetris
{

bool StartScreenView::show(StartScreenOption option)
{
    return OptionScreenView::show(opts, int(option));
}

}  // namespace Tetris
