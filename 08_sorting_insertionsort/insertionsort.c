#include <stdio.h>

void print_array(const int *arr, int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertionSort(int *arr, int n) {
    int pass = 1;
    for(int i = 0; i < n; i++) {
        int k = i;
        while(k > 0 && arr[k] < arr[k-1]) {
            printf("Pass %d: swap %d <-> %d => ", pass, arr[k], arr[k-1]);
            print_array(arr, 5);
            int tmp = arr[k];
            arr[k] = arr[k-1];
            arr[k-1] = tmp;
            pass++;
            k--;
        }
    }
}

int main(void) {
    int arr[] = {29,10,14,37,13};
    printf("Before: ");
    print_array(arr, 5);
    selectionSort(arr, 5);
    printf("After: ");
    print_array(arr, 5);
    return 0;
}