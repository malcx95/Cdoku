#include "cell.h"
#include <stdbool.h>

#ifndef BOARD_H
#define BOARD_H

extern const unsigned BOARD_WIDTH;

struct board {

    struct cell*** grid;

};

struct board* board_init();

void board_destroy(struct board* b);

struct cell* board_get_cell(unsigned x, unsigned y);

bool cell_is_covered(unsigned x, unsigned y);

void board_print(struct board* b);

void board_create_sudoku(struct board* b);

bool board_check_valid_sudoku(struct board* b);

#endif
