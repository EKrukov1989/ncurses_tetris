#include "HelpScreenView.h"
#include <ncurses.h>
#include <cmath>
#include <algorithm>
#include "Colors.h"

namespace
{

const std::string text =
"Controls.\n\n"

"F1 - help.\n"
"left CTRL - rotate tetraminoe.\n"
"left ARROW - move left.\n"
"right ARROW - move right.\n"
"down ARROW - move down.\n\n"

"* * *\n\n"

"Gameplay.\n\n"

"Tetris is primarily composed of a field of play in which pieces of different "
"geometric forms, called tetrominoes, descend from the top of the field. "
"During this descent, the player can move the pieces laterally and rotate them "
"until they touch the bottom of the field or land on a piece that had been "
"placed before it. The player can neither slow down the falling pieces nor stop "
"them, but can accelerate them in most versions. The objective of the game is "
"to use the pieces to create as many horizontal lines of blocks as possible. "
"When a line is completed, it disappears, and the blocks placed above fall one "
"rank. Completing lines grants points, and accumulating a certain number of "
"points or lines cleared moves the player up a level, which increases the number "
"of points granted per completed line.\n\n"

"In most versions, the speed of the falling pieces increases with each level, "
"leaving the player with less time to think about the placement.The player can "
"clear multiple lines at once, which can earn bonus points in some versions. "
"It is possible to complete up to four lines simultaneously with the use of "
"the I-shaped tetromino; this move is called a Tetris, and is the basis of the "
"game's title. If the player cannot make the blocks disappear quickly enough, "
"the field will start to fill, and when the pieces reach the top of the field "
"and prevent the arrival of additional pieces, the game ends. At the end of "
"each game, the player receives a score based on the number of lines that have "
"been completed. The game never ends with the player's victory; the player can "
"only complete as many lines as possible before an inevitable loss.\n\n"

"Since 1996, the Tetris Company has internally defined specifications and "
"guidelines that publishers must adhere to in order to be granted a license to "
"Tetris. The contents of these guidelines establish such elements as the "
"correspondence of buttons and actions, the size of the field of play, the "
"system of rotation, and others.\n\n"

"* * *\n\n"

"History.\n\n"

"Tetris is a puzzle video game created by Soviet software engineer Alexey "
"Pajitnov in 1984.It has been published by several companies for multiple "
"platforms, most prominently during a dispute over the appropriation of the "
"rights in the late 1980s. After a significant period of publication by "
"Nintendo, the rights reverted to Pajitnov in 1996, who co-founded the Tetris "
"Company with Henk Rogers to manage licensing.\n\n"

"In Tetris, players complete lines by moving differently shaped pieces "
"(tetrominoes), which descend onto the playing field. The completed lines "
"disappear and grant the player points, and the player can proceed to fill "
"the vacated spaces. The game ends when the uncleared lines reach the top of "
"the playing field. The longer the player can delay this outcome, the higher "
"their score will be. In multiplayer games, players must last longer than "
"their opponents; in certain versions, players can inflict penalties on "
"opponents by completing a significant number of lines. Some versions add "
"variations on the rules, such as three-dimensional displays or a system for "
"reserving pieces.\n\n"

"Built on simple rules, Tetris established itself as one of the great early "
"video games. By December 2011, Tetris had sold 202 million copies - "
"approximately 70 million physical units and 132 million paid mobile game "
"downloads - making it one of the best-selling video game franchises of all "
"time. The Game Boy version is one of the best-selling games of all time, with "
"more than 35 million copies sold. Tetris is available on over 65 platforms, "
"setting a Guinness world record for the most ported video game. Tetris is "
"rooted within popular culture and its popularity extends beyond the sphere "
"of video games; imagery from the game has influenced architecture, music and "
"cosplay. The game has also been the subject of various research studies that "
"have analyzed its theoretical complexity and have shown its effect on the "
"human brain following a session, in particular the Tetris effect.\n\n";

const std::size_t c_min_lines = 15;
const std::size_t c_min_cols = 37;

const std::size_t c_max_text_width = 80;
const std::string left_inscr = " HELP";
const std::string c_scroll = " ";
const std::size_t c_left_panel_width = left_inscr.size() + 2;
const std::size_t c_scroll_width = c_scroll.size() + 1;

}  // nameless namespace

namespace Tetris
{

HelpScreenView::HelpScreenView()
{
    prepare_text_();
}

void HelpScreenView::prepare_text_()
{  
    auto new_text_width = std::min(std::size_t(COLS) - c_left_panel_width - c_scroll_width, c_max_text_width );

    if (new_text_width == prepared_text_width_)
        return;

    prepared_text_.clear();

    std::size_t cur_idx = 0;

    while (cur_idx < text.size())
    {
        while (cur_idx < text.size() && text[cur_idx] == ' ')
            ++cur_idx;

        auto endline_idx = text.find('\n', cur_idx);

        if (endline_idx - cur_idx <= new_text_width + 1)
        {
            prepared_text_.push_back( text.substr(cur_idx, endline_idx - cur_idx) );
            cur_idx = endline_idx + 1;
            continue;
        }

        if (text.size() - cur_idx < new_text_width)
        {
            prepared_text_.push_back( text.substr(cur_idx ) );
            break;
        }

        auto space_idx = cur_idx + new_text_width;
        while ( space_idx > cur_idx && text[space_idx] != ' ')
            --space_idx;

        if ( space_idx == cur_idx )
        {
            prepared_text_.push_back( text.substr(cur_idx, new_text_width) );
            cur_idx += new_text_width;
            continue;
        }

        prepared_text_.push_back( text.substr(cur_idx, space_idx - cur_idx) );
        cur_idx 
        = space_idx;
    }

    prepared_text_width_ = new_text_width;
}

std::size_t HelpScreenView::show( std::size_t line_index )
{
    prepare_text_();
    auto n = prepared_text_.size();
    std::size_t max_line_idx = n - LINES;

    bkgd(COLOR_PAIR( int(InterfaceColor::DIALOG_SCREEN) ));
    clear();
    attrset( COLOR_PAIR( int(InterfaceColor::DIALOG_SCREEN)) );

    // left inscription

    unsigned x_shift = (COLS - prepared_text_width_ - c_left_panel_width - c_scroll_width ) / 2;
    move(0, x_shift);
    addstr(left_inscr.data());    

    // text

    auto m = std::min(n - line_index, std::size_t(LINES));
    for (std::size_t i = 0; i < m; ++i)
    {
        move(i, x_shift + c_left_panel_width);
        addstr(prepared_text_[line_index + i].data());
    }

    // vertical lines

    for (std::size_t i = 0; i < LINES; ++i)
    {
        move(i, x_shift + c_left_panel_width - 1);
        addch('|');
        move(i, x_shift + c_left_panel_width + prepared_text_width_ + 1);
        addch('|');
    }

    // scroll

    if ( n >= LINES )
    {
        auto scroll_h = std::size_t(std::round(double(LINES * LINES) / n));
        scroll_h = std::clamp(scroll_h, std::size_t(1), std::size_t(LINES-2));
        auto scroll_x = x_shift + c_left_panel_width + prepared_text_width_ + 1;

        std::size_t scroll_top = 0;
        if (line_index == 0) 
        {
            scroll_top = 0;
        }
        if (line_index == max_line_idx)
        {
            scroll_top = LINES - scroll_h;
        }
        else
        {
            scroll_top = std::size_t(std::round(double(LINES * line_index) / n));
            scroll_top = std::clamp( scroll_top, std::size_t(1), std::size_t(LINES - scroll_h - 1));
        }

        attrset( COLOR_PAIR( int(InterfaceColor::DIALOG_SCREEN_CHOSEN)) );
        for (int i = 0; i < scroll_h; ++i)
        {
            move(scroll_top + i, scroll_x);
            addstr(c_scroll.data());
        }
    }

    refresh();
    return max_line_idx;
}

}  // namespace Tetris
