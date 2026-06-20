#include <stdio.h>
#include "stats.h"

int main(void) {
    const double arr[] = {2, 4, 4, 4, 5, 5, 7, 9};
    printf("Min\t =%f\n", stats_min(arr, 8));
    printf("Max\t =%f\n", stats_max(arr, 8));
    printf("Sum\t =%f\n", stats_sum(arr, 8));
    printf("Mean\t =%f\n", stats_mean(arr, 8));
    printf("Variance\t =%f\n", stats_variance(arr, 8));
    printf("Std Dev\t =%f\n", stats_stddev(arr, 8));

    return 0;
}