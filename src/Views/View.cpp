#include "View.h"
#include "StartScreenView.h"
#include <ncurses.h>

namespace Tetris
{

View::View()
{
}

bool View::init()
{
    initscr();
    curs_set(0);

    if (start_color() != OK)
        return false;

    init_pair(int(InterfaceColor::DIALOG_SCREEN), COLOR_WHITE, COLOR_BLUE);
    init_pair(int(InterfaceColor::DIALOG_SCREEN_CHOSEN), COLOR_BLACK, COLOR_WHITE);

    return true;
}

View::~View()
{
    endwin();
}

void View::show_start_screen(StartScreenView::Option option)
{
    StartScreenView::show(option);
}

void View::show_pause_screen(PauseScreenView::Option option)
{
    PauseScreenView::show(option);
}

void View::show_custom_screen(CustomScreenView::Option option, CustomScreenView::Settings settings)
{
    CustomScreenView::show(option, settings);
}

}  // namespace Tetris
