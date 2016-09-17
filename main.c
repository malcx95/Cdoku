#include <ncurses.h>
#include <menu.h>
#include "board.h"

int main(int argc, char* argv[]) {
    //initscr();
    //endwin();
    struct board* main_board = board_init();
    board_print(main_board);
    return 0;
}
