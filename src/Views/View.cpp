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
}

bool View::show_start_screen(StartScreenOption option) const
{
    StartScreenView::show(option);
    return true;  // todo
}

bool View::show_pause_screen(PauseScreenView::Option option) const
{
    PauseScreenView::show(option);
    return true;  // todo
}

bool View::show_custom_screen(CustomScreenView::Option option, CustomScreenView::Settings settings) const
{
    CustomScreenView::show(option, settings);
    return true;  // todo
}

bool View::show_gameover_screen(GameoverScreenView::Scores scores) const
{
    GameoverScreenView::show(scores);
    return true;  // todo
}

bool View::show_small_screen() const
{
    SmallScreenView::show();
    return true;  // todo
}

bool View::show_help_screen(std::size_t line_index, std::size_t& max_pos) const
{
    static HelpScreenView hsv;
    hsv.show( line_index, max_pos );
    return true;  // todo
}

bool View::show_game_screen(const GameScreenView::State& s) const
{
    GameScreenView::show(s);
    return true;  // todo
}

}  // namespace Tetris
