#include <stdio.h>

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Builds a sorted portion at the front of the array one element at a
// time, "inserting" each new element into the correct position among
// the already-sorted elements before it.
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Repeatedly finds the smallest remaining element and swaps it into its
// correct sorted position.
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

int main() {
    int n, choice;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    printf("\nChoose a sorting method:\n");
    printf("1. Insertion Sort\n");
    printf("2. Bubble Sort\n");
    printf("3. Selection Sort\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            insertionSort(arr, n);
            printf("\nSorted using Insertion Sort: ");
            break;
        case 2:
            bubbleSort(arr, n);
            printf("\nSorted using Bubble Sort: ");
            break;
        case 3:
            selectionSort(arr, n);
            printf("\nSorted using Selection Sort: ");
            break;
        default:
            printf("Invalid choice.\n");
            return 1;
    }

    printArray(arr, n);
    return 0;
}
