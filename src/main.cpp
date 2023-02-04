#include <ncurses.h>
#include <thread>
#include <chrono>
#include <stdlib.h>
#include "Views/View.h"
#include "Views/Colors.h"

std::vector<std::vector<Tetris::TetrisColor>> make_rand_rect(int w, int h)
{
    auto n = int(Tetris::TetrisColor::LAST) - int(Tetris::TetrisColor::TRANSPARENT);
    auto get_rand_color = [n]() -> Tetris::TetrisColor
    {
        return Tetris::TetrisColor( int(Tetris::TetrisColor::TRANSPARENT) + rand() % n);
    };

    std::vector<std::vector<Tetris::TetrisColor>> r;
    for (int i = 0; i < h; ++i)
    {
        r.push_back({});
        for (int j = 0; j < w; ++j)
        {
            r.back().push_back( get_rand_color());
        }
    }
    return r;
}

Tetris::GameScreenView::State make_game_state()
{
    Tetris::GameScreenView::State gs;
    gs.game_rect = make_rand_rect(8,15);
    gs.next_tetr = make_rand_rect(4,4);
    gs.lines = 3;
    gs.speed = 10;
    gs.score = 5000;
    gs.timer = 3125;
    return gs;
}

int main()
{
    Tetris::View v;
    if (!v.init())
        return 1;

    auto ti = std::chrono::milliseconds(500);

    v.show_start_screen(Tetris::StartScreenView::Option::CUSTOM);
    std::this_thread::sleep_for(std::chrono::milliseconds(ti));

    v.show_pause_screen(Tetris::PauseScreenView::Option::RESUME);
    std::this_thread::sleep_for(std::chrono::milliseconds(ti));

    Tetris::CustomScreenView::Settings settings = {3,25,12};
    v.show_custom_screen(Tetris::CustomScreenView::Option::SPEED, settings);
    std::this_thread::sleep_for(std::chrono::milliseconds(ti));

    Tetris::GameoverScreenView::Scores scores = {3,25,12};
    v.show_gameover_screen(scores);
    std::this_thread::sleep_for(std::chrono::milliseconds(ti));

    v.show_small_screen();
    std::this_thread::sleep_for(std::chrono::milliseconds(ti));

    v.show_help_screen( 10 );
    std::this_thread::sleep_for(std::chrono::milliseconds(ti));

    auto gs = make_game_state();
    v.show_game_screen(gs);

    getch();
    return 0;
}
