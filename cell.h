#include <stdbool.h>

#ifndef CELL_H
#define CELL_H


struct cell {

    unsigned value;
    
    bool uncovered;

};

struct cell* cell_init();
void cell_destroy(struct cell* c);

#endif
