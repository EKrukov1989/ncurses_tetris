#include "View.h"
#include "StartScreenView.h"
#include <ncurses.h>
#include "SmallScreenView.h"
#include "HelpScreenView.h"

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

    init_pair(int(TetrisColor::BACKGROUND), COLOR_BLACK, COLOR_BLACK);
    init_pair(int(TetrisColor::FULL_LINE),  COLOR_BLACK, COLOR_WHITE);
    init_pair(int(TetrisColor::FIGURE_1),   COLOR_BLACK, COLOR_RED);
    init_pair(int(TetrisColor::FIGURE_2),   COLOR_BLACK, COLOR_YELLOW);
    init_pair(int(TetrisColor::FIGURE_3),   COLOR_BLACK, COLOR_GREEN);
    init_pair(int(TetrisColor::FIGURE_4),   COLOR_BLACK, COLOR_MAGENTA);

    return true;
}

View::~View()
{
    endwin();
}

void View::show_start_screen(StartScreenView::Option option) const
{
    StartScreenView::show(option);
}

void View::show_pause_screen(PauseScreenView::Option option) const
{
    PauseScreenView::show(option);
}

void View::show_custom_screen(CustomScreenView::Option option, CustomScreenView::Settings settings) const
{
    CustomScreenView::show(option, settings);
}

void View::show_gameover_screen(GameoverScreenView::Scores scores) const
{
    GameoverScreenView::show(scores);
}

void View::show_small_screen() const
{
    SmallScreenView::show();
}

unsigned View::show_help_screen( unsigned line_index) const
{
    static HelpScreenView hsv;
    return hsv.show( line_index );
}

void View::show_game_screen(const GameScreenView::State& s) const
{
    GameScreenView::show(s);
}

}  // namespace Tetris
