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

    // return false if window size too small for this screen
    bool show_start_screen(StartScreenOption) const;
    bool show_pause_screen(PauseScreenView::Option) const;
    bool show_custom_screen(CustomScreenView::Option, CustomScreenView::Settings) const;
    bool show_gameover_screen(GameoverScreenView::Scores) const;
    bool show_small_screen() const;
    bool show_game_screen(const GameScreenView::State& ) const;
    // next function shows some help-text that hardcoded inside view.
    // "line_index" - defines the part of the text, that will be shown on the screen.
    // max_pos - maximal possible line index.
    bool show_help_screen(std::size_t line_index, std::size_t& max_pos) const;
};

}  // namespace Tetris