#include "board.h"
#include <stdlib.h>
#include <stdio.h>

const unsigned BOARD_WIDTH = 9;

struct board* board_init() {
    unsigned x, y; 
    struct board* b = (struct board*) malloc(sizeof(struct board));
    b->grid = (struct cell***) malloc(sizeof(struct cell**) * BOARD_WIDTH);
    for (x = 0; x < BOARD_WIDTH; ++x) {
        b->grid[x] = 
            (struct cell**) malloc(sizeof(struct cell*) * BOARD_WIDTH);
        for (y = 0; y < BOARD_WIDTH; ++y) {
            b->grid[x][y] = cell_init();
        }
    }
    return b;
}

void board_destroy(struct board* b) {
    unsigned x, y; 
    for (x = 0; x < BOARD_WIDTH; ++x) {
        for (y = 0; y < BOARD_WIDTH; ++y) {
            cell_destroy(b->grid[x][y]);
        }
    }
}

void board_print(struct board* b) {
    unsigned x, y;
    for (x = 0; x < BOARD_WIDTH; ++x) {
        printf("\n");
        if (x % 3 == 0) {
            printf("\n");
        }
        for (y = 0; y < BOARD_WIDTH; ++y) {
            if (y % 3 == 0) {
                printf(" ");
            }
            printf("%d ", b->grid[x][y]->value);
        }
    }
    printf("\n");
}
