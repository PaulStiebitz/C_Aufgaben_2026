#include "stats.h"
#include <math.h>
#define NULL ((void *)0)

double stats_min(const double *arr, int n) {
    if(arr == NULL || n <= 0) {
        return 0;
    }
    int smallest = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] < arr[smallest]) {
            smallest = i;
        }
    }
    return arr[smallest];
}

double stats_max(const double *arr, int n) {
    if(arr == NULL || n <= 0) {
        return 0;
    }
    int biggest = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] > arr[biggest]) {
            biggest = i;
        }
    }
    return arr[biggest];
}

double stats_sum(const double *arr, int n) {
    if(arr == NULL || n <= 0) {
        return 0;
    }
    double sum = 0;
    for(int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

double stats_mean(const double *arr, int n) {
    if(arr == NULL || n <= 0) {
        return 0;
    }   
    double sum = stats_sum(arr, n);
    return sum / n;
}

double stats_variance(const double *arr, int n) {
    if(arr == NULL || n <= 0) {
        return 0;
    }
    double sqaured_abw = 0;
    double mean = stats_mean(arr, n);

    for(int i = 0; i < n; i++) {
        sqaured_abw += (arr[i] - mean) * (arr[i] - mean);
    }

    double variance = (1.0/n) * sqaured_abw;
    return variance;
}

double stats_stddev(const double *arr, int n) {
    if(arr == NULL || n <= 0) {
        return 0;
    }
    double variance = stats_variance(arr, n);
    double stddev = sqrt(variance);
    return stddev;
}