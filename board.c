#include "board.h"
#include <stdlib.h>
#include <stdio.h>

const unsigned BOARD_WIDTH = 9;

struct board* board_init() {
    struct board* b = (struct board*) malloc(sizeof(struct board));
    b->grid = (struct cell***) malloc(sizeof(struct cell**) * BOARD_WIDTH);
    for (unsigned x = 0; x < BOARD_WIDTH; ++x) {
        b->grid[x] = 
            (struct cell**) malloc(sizeof(struct cell*) * BOARD_WIDTH);
        for (unsigned y = 0; y < BOARD_WIDTH; ++y) {
            b->grid[x][y] = cell_init();
        }
    }
    return b;
}

void board_destroy(struct board* b) {
    for (unsigned x = 0; x < BOARD_WIDTH; ++x) {
        for (unsigned y = 0; y < BOARD_WIDTH; ++y) {
            cell_destroy(b->grid[x][y]);
        }
    }
}

void board_print(struct board* b) {
    for (unsigned x = 0; x < BOARD_WIDTH; ++x) {
        printf("\n");
        if (x % 3 == 0) {
            printf("\n");
        }
        for (unsigned y = 0; y < BOARD_WIDTH; ++y) {
            if (y % 3 == 0) {
                printf(" ");
            }
            printf("%d ", b->grid[x][y]->value);
        }
    }
    printf("\n");
}


bool create_sudoku_help(struct board* b, unsigned x, unsigned y) {
    if (x == BOARD_WIDTH - 1 && y == BOARD_WIDTH - 1) {
        return true;
    } else if (x == BOARD_WIDTH) {
        return create_sudoku_help(b, 0, y + 1);
    } else {
        
    }
}

void board_create_sudoku(struct board* b) {

    // TODO use the board's grid, send
    // it to a helper function which starts at (0, 0).
    // In the function, check if we reached the last square.
    // If so, return true (valid sudoku).
    // If 
}

bool check_square(struct board* b, unsigned x, unsigned y) {
    const unsigned expected_prod = 362880;
    unsigned prod = 1;

    // multiply all numbers together 
    for (unsigned c = 0; c < BOARD_WIDTH / 3; ++c) {
        for (unsigned r = 0; r < BOARD_WIDTH / 3; ++r) {
            prod *= b->grid[x + c][y + c]->value;
        }
    }
    return prod == expected_prod;
}

bool check_row(struct board* b, unsigned row) {
    const unsigned expected_prod = 362880;
    unsigned prod = 1;

    for (unsigned i = 0; i < BOARD_WIDTH; ++i) {
        prod *= b->grid[i][row]->value;
    }
    
    return prod == expected_prod;
}

bool check_column(struct board* b, unsigned col) {
    const unsigned expected_prod = 362880;
    unsigned prod = 1;

    for (unsigned i = 0; i < BOARD_WIDTH; ++i) {
        prod *= b->grid[col][i]->value;
    }
    
    return prod == expected_prod;
}

bool board_check_valid_sudoku(struct board* b) {
    // check big squares
    for (unsigned x = 0; x < BOARD_WIDTH / 3; ++x) {
        for (unsigned y = 0; y < BOARD_WIDTH / 3; ++y) {
            if (!check_square(b, x, y)) return false;
        }
    }

    for (unsigned x = 0; x < BOARD_WIDTH; ++x) {
        if (!(check_row(b, x) && check_column(b, x))) {
            return false;
        }
    }

    return true;
}

