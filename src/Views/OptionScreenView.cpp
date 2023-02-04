#include "OptionScreenView.h"
#include "Colors.h"
#include <ncurses.h>

namespace Tetris
{

void OptionScreenView::show(const std::vector<std::string>& options, int chosen_option)
{
    bkgd(COLOR_PAIR( int(InterfaceColor::DIALOG_SCREEN) ));
    clear();

    auto h = options.size();
    auto w = options.front().length();
    int y = (LINES - h) / 2;
    int x = (COLS - w) / 2;

    for (int i = 0; i < options.size(); ++i)
    {
        attrset(COLOR_PAIR( i != chosen_option ? int(InterfaceColor::DIALOG_SCREEN)
                                               : int(InterfaceColor::DIALOG_SCREEN_CHOSEN) ));
        move(y + i, x);
        addstr(options[i].data());
    }
    refresh();
}

}  // namespace Tetris
