#include <ncurses.h>
#include "Views/View.h"

int main()
{
    Tetris::View v;
    if (!v.init())
        return 1;
    v.show_start_screen(Tetris::StartScreenView::Option::CUSTOM);
    getch();

    return 0;
}
