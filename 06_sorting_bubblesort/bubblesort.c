#include <stdio.h>

void print_array(const int *arr, int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubbleSort(int *arr, int n) {
    int end = n;
    for(int i = 0; i < n; i++) {
        int swapped = 0;
        for(int j = 0; j < end - 1; j++) {
            if(arr[j+1] < arr[j]) {
                int tmp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = tmp;
                swapped = 1;
            }
        }

        if(swapped == 0) {
            return;
        }
        end--;
    }
}

int main(void) {
    int arr[] = {64,34,25,12,22,11,90};
    
    printf("Before: ");
    print_array(arr, 7);
    
    bubbleSort(arr, 7);

    printf("After: ");
    print_array(arr, 7);

    return 0;
}