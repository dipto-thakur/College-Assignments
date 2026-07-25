#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Ensures the subtree rooted at index i satisfies the max-heap property
// (every parent >= its children), assuming the subtrees below i are
// already valid heaps. If arr[i] is smaller than one of its children,
// it gets swapped down, and the process repeats at the child's position.
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);   // the swapped-down subtree might now be invalid, fix it too
    }
}

void heapSort(int arr[], int n) {
    // Phase 1: build a max-heap out of the raw array. Starting from the
    // last non-leaf node and working backward means every heapify call
    // only ever needs its children to already be valid heaps, which
    // they are, since we're going in reverse.
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Phase 2: repeatedly pull the max (always at the root) out to the
    // end of the array, shrink the heap by one, and re-heapify what's left.
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
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

    heapSort(arr, n);

    printf("Sorted array:   ");
    printArray(arr, n);

    return 0;
}
