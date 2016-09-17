#include <stdbool.h>


struct cell {

    int value;
    
    bool uncovered;

};

struct cell* cell_init();
void cell_destroy(struct cell* c);
