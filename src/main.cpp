#include "Application.h"

// includes for tests
#include <ncurses.h>
#include <thread>
#include <chrono>
#include <stdlib.h>
#include "Views/View.h"
#include "Views/Colors.h"
#include "Controller.h"
#include "EventQueue.h"
#include "Enums.h"
#include <iostream>
#include <string>

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
    gs.game_rect = make_rand_rect(10,18);
    gs.next_tetr = make_rand_rect(4,4);
    gs.lines = 3;
    gs.speed = 10;
    gs.score = 5000;
    gs.timer = 3125;
    return gs;
}

void view_test()
{
    Tetris::View v;
    if (!v.init())
        return;

    auto ti = std::chrono::milliseconds(500);

    v.show_start_screen(Tetris::StartScreenOption::CUSTOM);
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

    std::size_t out = 0;
    v.show_help_screen( 10, out );
    std::this_thread::sleep_for(std::chrono::milliseconds(ti));

    auto gs = make_game_state();
    v.show_game_screen(gs);

    getch();
}

void controller_test()
{
    std::vector<std::string> vv =
    {
        "INVALID",
        "START",
        "STOP",
        "LEFT",
        "RIGHT",
        "UP",
        "DOWN",
        "LEAVE",
        "ROTATE",
        "CONFIRM",
        "PAUSE",
        "HELP",
        "RESIZE",
        "LAST"
    };

    initscr();
    Tetris::EventQueue q;
    Tetris::Controller c(q);

    auto t0 = std::chrono::high_resolution_clock::now();
    c.start();
    std::cout << "start" << std::endl;
    for (int i = 0; i < 10; ++i)
    {
        auto ev_info = q.wait_and_get_event();
        auto td = ev_info.time - t0;
        auto td_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(td).count();
        std::cout << int(ev_info.event) << " " << vv[int(ev_info.event)] << " " << td_ns << std::endl;
    }
    std::cout << "finish" << std::endl;
    endwin();
}

int main()
{
    Tetris::Application app;
    app.run();
    return 0;
}
