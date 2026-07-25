#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Rearranges arr[low..high] so that everything smaller than the pivot
// ends up before it and everything larger ends up after it, then
// returns the pivot's final resting index. This uses the last element
// as the pivot (the Lomuto partition scheme).
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;   // index of the last element known to be <= pivot

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);   // place the pivot in its correct spot
    return i + 1;
}

// Partitions the array around a pivot, then recursively sorts the two
// sides independently, since after partitioning, everything on the left
// is already guaranteed smaller than everything on the right.
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    printf("\nOriginal array: ");
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    printf("Sorted array:   ");
    printArray(arr, n);

    return 0;
}
