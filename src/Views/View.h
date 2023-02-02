#pragma once
#include "StartScreenView.h"
#include "PauseScreenView.h"
#include "CustomScreenView.h"
#include "GameoverScreenView.h"

namespace Tetris
{

class View
{
    friend class OptionScreenView;

    enum class InterfaceColor
    {
        DIALOG_SCREEN = 1,
        DIALOG_SCREEN_CHOSEN,
        LAST
    };

public:
    enum class TetrisColor
    {
        BACKGROUND = int(InterfaceColor::LAST),
        FULL_LINE,
        FIGURE_1,
        FIGURE_2,
        FIGURE_3,
        FIGURE_4
    };

    View();
    bool init();
    ~View();

    void show_start_screen(StartScreenView::Option) const;
    void show_pause_screen(PauseScreenView::Option) const;
    void show_custom_screen(CustomScreenView::Option, CustomScreenView::Settings) const;
    void show_gameover_screen(GameoverScreenView::Scores) const;
    void show_small_screen() const;
    // void show_help_screen( std::size_t current_index) const;
    // 	GAME_SCREEN,
};

}  // namespace Tetris