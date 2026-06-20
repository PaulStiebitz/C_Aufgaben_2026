#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(void) {
    List *l = calloc(1, sizeof(List));
    list_init(l);

    for(int i = 0; i < 5; i++) {
        list_push_front(l, i);
    }

    list_print(l);

    for(int i = 0; i < 5; i++) {
        list_push_back(l, i);
    }
    list_print(l);
    list_free(l);

    list_print(l);
    free(l);
    return 0;
}