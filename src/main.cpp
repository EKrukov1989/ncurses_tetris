#include <ncurses.h>

int main()
{
    initscr();
    curs_set(0);
    if (start_color() != OK)
        return 1;

    init_pair(1, COLOR_BLACK, COLOR_GREEN);
    attrset(COLOR_PAIR(1));
    move(3,6);
    addstr("hello, ncurses!");
    refresh();
    getch();

    endwin();
    return 0;
}