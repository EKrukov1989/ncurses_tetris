#include "StartScreenView.h"
#include <vector>
#include <ncurses.h>
#include <string>
#include "View.h"

namespace
{

// Content and order of strings in next array must correspond with enum!
std::vector<std::string> opts = { " start  ",
                                  " custom ",
                                  "  help  ",
                                  "  quit  " };

}  // nameless namespace

namespace Tetris
{

void StartScreenView::show_with_option(Option option)
{
    bkgd(COLOR_PAIR( int(View::InterfaceColor::DIALOG_SCREEN) ));
    
    auto h = opts.size();
    auto w = opts.front().length();
    int y = (LINES - h) / 2;
    int x = (COLS - w) / 2;

    for (int i = 0; i < opts.size(); ++i)
    {
        attrset(COLOR_PAIR( i != int(option) ? int(View::InterfaceColor::DIALOG_SCREEN)
                                             : int(View::InterfaceColor::DIALOG_SCREEN_CHOSEN) ));
        move(y + i, x);
        addstr(opts[i].data());
    }
    refresh();
}

}  // namespace Tetris
