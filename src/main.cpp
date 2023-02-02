#include <ncurses.h>
#include <thread>
#include <chrono>
#include "Views/View.h"


int main()
{
    Tetris::View v;
    if (!v.init())
        return 1;

    v.show_start_screen(Tetris::StartScreenView::Option::CUSTOM);

    std::this_thread::sleep_for(std::chrono::milliseconds(1500));

    v.show_pause_screen(Tetris::PauseScreenView::Option::RESUME);

    std::this_thread::sleep_for(std::chrono::milliseconds(1500));

    Tetris::CustomScreenView::Settings s;
    s.speed = 3;
    s.height = 25;
    s.width = 12;
    v.show_custom_screen(Tetris::CustomScreenView::Option::SPEED, s);

    getch();
    return 0;
}
