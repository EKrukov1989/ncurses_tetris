#include "GameScreenView.h"
#include <ncurses.h>
#include "Colors.h"
#include <algorithm>

namespace
{

/*        
          Disposition on screen:

          GGGGGGGGGGGGGGGGGGGG
          GGGGGGGGGGGGGGGGGGGG
          GGGGGGGGGGGGGGGGGGGG   00:01:16
          GGGGGGGGGGGGGGGGGGGG
          GGGGGGGGGGGGGGGGGGGG
          GGGGGGGGGGGGGGGGGGGG   next:
          GGGGGGGGGGGGGGGGGGGG
          GGGGGGGGGGGGGGGGGGGG   NNNNNNNN
          GGGGGGGGGGGGGGGGGGGG   NNNNNNNN
          GGGGGGGGGGGGGGGGGGGG   NNNNNNNN
          GGGGGGGGGGGGGGGGGGGG   NNNNNNNN
          GGGGGGGGGGGGGGGGGGGG  
          GGGGGGGGGGGGGGGGGGGG   speed: 3
          GGGGGGGGGGGGGGGGGGGG   lines: 100
          GGGGGGGGGGGGGGGGGGGG   score: 260
          GGGGGGGGGGGGGGGGGGGG   <----------->
          GGGGGGGGGGGGGGGGGGGG      info_w
          GGGGGGGGGGGGGGGGGGGG

<--------><------------------><->
 x_shift    game_rect_width    |
                              info_shift  
legend:
G - game rectangle
N - next tetraminoe

*/

const int c_info_shift = 3;
const int c_info_w = 13;

const int c_timer_y_shift = 1;
const int c_next_y_shift = 4;
const int c_next_tetr_y_shift = 6;

void s_draw_rect(const std::vector<std::vector<Tetris::TetrisColor>>& rect,
               unsigned x, unsigned y)
{
    auto game_rect_w = rect.front().size();
    auto game_rect_h = rect.size();
    for (int i = 0; i < game_rect_h; ++i)
    {
        for (int j = 0; j < game_rect_w; ++j)
        {
            if (rect[i][j] == Tetris::TetrisColor::TRANSPARENT)
                continue;
            attrset( COLOR_PAIR( int(Tetris::TetrisColor(rect[i][j])) ) );
            move(y + i, x + j * 2);
            addstr("  ");
        }   
    }
}

std::string s_format_time(unsigned time)
{
    std::vector<unsigned> nums;
    while (time)
    {
        nums.push_back(time % 60);
        time /= 60;
    }
    nums.resize(3, 0);

    auto to_str = [](unsigned z) -> std::string
    {
        auto r = std::to_string(z);
        return std::string( 2 - r.length(), '0') + r;
    };

    return to_str(nums[2]) + ":" + to_str(nums[1]) + ":" + to_str(nums[0]);
}

}  // nameless namespace

namespace Tetris
{

bool GameScreenView::show( State s )
{
    auto next_tetr_w = s.next_tetr.front().size() * 2;
    auto next_tetr_h = s.next_tetr.size();
    auto game_rect_w = s.game_rect.front().size() * 2;
    auto game_rect_h = s.game_rect.size();
    auto total_w = game_rect_w + c_info_shift + std::max(int(next_tetr_w), c_info_w);
    auto total_h = game_rect_h;

    if (COLS < total_w + 2 || LINES < total_h + 2)
        return false;

    auto x_shift = (COLS - total_w) / 2;
    auto y_shift = (LINES - total_h) / 2;

    bkgd(COLOR_PAIR( int(InterfaceColor::DIALOG_SCREEN) ));
    clear();

    // game rectangle
    s_draw_rect(s.game_rect, x_shift, y_shift);

    // next tetr
    auto info_x = x_shift + game_rect_w + c_info_shift;
    s_draw_rect(s.next_tetr, info_x, y_shift + c_next_tetr_y_shift);

    // timer and info
    attrset( COLOR_PAIR( int(InterfaceColor::DIALOG_SCREEN)) );

    move(y_shift + c_timer_y_shift, info_x);
    addstr(s_format_time(s.timer).data());
    move(y_shift + c_next_y_shift, info_x);
    addstr("next:");
    move(y_shift + c_next_tetr_y_shift + next_tetr_h + 2, info_x);
    addstr( (std::string("speed: ")+ std::to_string(s.speed)).data() );
    move(y_shift + c_next_tetr_y_shift + next_tetr_h + 3, info_x);
    addstr( (std::string("lines: ")+ std::to_string(s.lines)).data() );
    move(y_shift + c_next_tetr_y_shift + next_tetr_h + 4, info_x);
    addstr( (std::string("score: ")+ std::to_string(s.score)).data() );
    refresh();
    return true;
}

}  // namespace Tetris
