#include "OptionScreenView.h"
#include "Colors.h"
#include <ncurses.h>

namespace Tetris
{

bool OptionScreenView::show(const std::vector<std::string>& options, int chosen_option)
{
    auto h = options.size();
    auto w = options.front().length();  // we suppose that all options have the same length

    if ( h > LINES || w > COLS )
        return false;

    bkgd(COLOR_PAIR( int(InterfaceColor::DIALOG_SCREEN) ));
    clear();

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

    return true;
}

}  // namespace Tetris
