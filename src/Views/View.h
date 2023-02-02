#pragma once
#include "Enums.h"
#include "StartScreenView.h"
#include "PauseScreenView.h"
#include "CustomScreenView.h"

namespace Tetris
{

class View
{
    friend class OptionScreenView;
    friend class StartScreenView;
    friend class PauseScreenView;
    friend class CustomScreenView;

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

    void show_start_screen(StartScreenView::Option);
    void show_pause_screen(PauseScreenView::Option);
    void show_custom_screen(CustomScreenView::Option, CustomScreenView::Settings);
    // 	GAME_SCREEN,
    // 	HELP_SCREEN,
    // 	GAME_OVER,	
    //  SMALL_SCREEN

};

}  // namespace Tetris