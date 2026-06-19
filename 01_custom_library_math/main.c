#include <stdio.h>
#include "mathlib.h"

int main(void) {
    int a = 3;
    int b = 4;

    printf("Add: %d\n", add(a, b));
    printf("Add: %d\n", substract(a, b));
    printf("Add: %d\n", multiply(a, b));
    printf("Add: %f\n", divide(a, b));
    printf("Add: %d\n", absolute(-3));
    return 0;
}

