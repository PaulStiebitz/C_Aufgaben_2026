#include <stdio.h>

void print_array(const int *arr, int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void selectionSort(int *arr, int n) {
    int pass = 1;
    for(int i = 0; i < n; i++) {
        int smallest = i;
        for(int j = i; j < n; j++) {
            if(arr[j] < arr[smallest]) {
                smallest = j;
            }
        }
        printf("Pass %d: swap %d <-> %d => ", pass, arr[smallest], arr[i]);
        print_array(arr, n);
        int tmp = arr[smallest];
        arr[smallest] = arr[i];
        arr[i] = tmp;
        pass++;
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