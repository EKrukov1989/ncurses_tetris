#include <ncurses.h>
#include <thread>
#include <chrono>
#include "Views/View.h"


int main()
{
    Tetris::View v;
    if (!v.init())
        return 1;

    auto ti = std::chrono::milliseconds(1500);

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


    getch();
    return 0;
}
