#include <stdio.h>


void printArr(int *arr, int length) {
    for(int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void heapify(int *arr, int length, int parentPos) {
    int largest = parentPos;
    int left = parentPos * 2 + 1;
    int right = parentPos * 2 + 2;

    if(left < length && arr[left] > arr[largest]) {
        largest = left;
    }

    if(right < length && arr[right] > arr[largest]) {
        largest = right;
    }

    if(largest != parentPos) {
        swap(&arr[largest], &arr[parentPos]);
        heapify(arr, length, largest);
    }
}

void buildHeap(int *arr, int length) {
    int lastParent = (length - 1) / 2;
    for(int i = lastParent; i >= 0; i--) {
        heapify(arr, length, i);
    }
}

void HeapSort(int *arr, int length) {
    if(arr == NULL || length < 1) {
        return;
    }

    buildHeap(arr, length);
    for(int end = length - 1; end > 0; end--) {
        swap(&arr[0], &arr[end]);
        heapify(arr, end, 0);
    }
}

void quicksort(int *arr, int left, int right) {
    if(left < right) {
        int pivot = arr[right];
        int low = left - 1;

        for(int i = left; i < right; i++) {
            if(arr[i] <= pivot) {
                low++;
                int tmp = arr[low];
                arr[low] = arr[i];
                arr[i] = tmp;
            }
        }

        int tmp = arr[low + 1];
        arr[low + 1] = arr[right];
        arr[right] = tmp;

        int pivot_pos = low + 1;
        quicksort(arr, left, pivot_pos - 1);
        quicksort(arr, pivot_pos + 1, right);
    }
}

int main(void) {
    int arr[] = {3,54,1,0,2};

    printf("Before: ");
    printArr(arr, 5);
    //HeapSort(arr, 5);
    quicksort(arr, 0, 4);
    printf("\nAfter: ");
    printArr(arr, 5);

    return 0;
}