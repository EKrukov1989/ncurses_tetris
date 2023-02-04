#pragma once
#include "StartScreenView.h"
#include "PauseScreenView.h"
#include "CustomScreenView.h"
#include "GameoverScreenView.h"
#include "GameScreenView.h"

namespace Tetris
{

class View
{
public:
    View();
    bool init();
    ~View();

    void show_start_screen(StartScreenView::Option) const;
    void show_pause_screen(PauseScreenView::Option) const;
    void show_custom_screen(CustomScreenView::Option, CustomScreenView::Settings) const;
    void show_gameover_screen(GameoverScreenView::Scores) const;
    void show_small_screen() const;
    void show_game_screen(const GameScreenView::State& ) const;

    // next function shows some help-text that hardcoded inside view.
    // "line_index" - defines the part of the text, that will be shown on the screen.
    // return value - maximal possible line index.
    unsigned show_help_screen( unsigned line_index) const;

};

}  // namespace Tetris