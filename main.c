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
    int lastParentPos = (length - 1) / 2;
    for(int i = lastParentPos; i >= 0; i--) {
        heapify(arr, length, i);
    }
}

void heapSort(int *arr, int length) {
    if(arr != NULL && length > 0) {
        buildHeap(arr, length);

        for(int end = length - 1; end > 0; end--) {
            swap(&arr[0], &arr[end]);
            heapify(arr, end, 0);
        }
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

        int pivotPos = low + 1;
        quicksort(arr, left, pivotPos - 1);
        quicksort(arr, pivotPos + 1, right);
    }
}

void merge(int *arr, int left, int mid, int right) {
    int leftindex = left;
    int rightindex = mid + 1;

    while(leftindex <= mid && rightindex <= right) {
        if(arr[leftindex] < arr[rightindex]) {
            leftindex++;
        } else {
            int tmp = arr[rightindex];
            int k = rightindex;

            while(k > leftindex) {
                arr[k] = arr[k-1];
                k--;
            }

            arr[leftindex] = tmp;
            leftindex++;
            mid++;
            rightindex++;
        }
    }
}

void mergesort(int *arr, int left, int right) {
    if(arr != NULL && left < right) {
        int mid = (left + right) / 2;
        mergesort(arr, left, mid);
        mergesort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}

void bubbleSort(int *arr, int length) {
    int end = length;
    for(int i = 0; i < length; i++) {
        int swapped = 0;
        for(int j = 0; j < end - 1; j++) {
            if(arr[j] > arr[j+1]) {
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
                swapped = 1;
            }
        }

        if(swapped == 0) {
            return;
        }
        end--;
    }
}

void insertionSort(int *arr, int length) {
    for(int i = 0; i < length; i++) {
        int k = i;

        while(k > 0 && arr[k-1] > arr[k]) {
            int tmp = arr[k-1];
            arr[k-1] = arr[k];
            arr[k] = tmp;
            k--;
        }
    }
}

void selectionSort(int *arr, int length) {
    for(int i = 0; i < length; i++) {
        int smallest = i;
        for(int j = i; j < length; j++) {
            if(arr[j] < arr[smallest]) {
                smallest = j;
            }
        }

        int tmp = arr[smallest];
        arr[smallest] = arr[i];
        arr[i] = tmp;
    }
}

int main(void) {
    int arr[] = {3,5,6,7,2};
    //selectionSort(arr, 5);
    //insertionSort(arr, 5);
    //bubbleSort(arr, 5);
    //mergesort(arr, 0, 4);
    //quicksort(arr, 0, 4);
    //heapSort(arr, 5);

    printArr(arr, 5);
    return 0;
}