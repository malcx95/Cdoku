#include "cell.h"
#include <stdlib.h>

struct cell* cell_init() {
    struct cell* c = (struct cell*) malloc(sizeof(struct cell));
    c->uncovered = false;
    c->value = 0;
    return c;
}

void cell_destroy(struct cell* c) {
    free(c);
}
