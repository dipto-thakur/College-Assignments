#include <stdio.h>

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;   // found at index i
        }
    }
    return -1;   // not found
}

// Binary search needs the array sorted first, this assumes it already is
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
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

int main() {
    int n, key, choice, result;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    printf("\nChoose search method:\n");
    printf("1. Linear Search\n");
    printf("2. Binary Search\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        result = linearSearch(arr, n, key);
    } else if (choice == 2) {
        // binary search needs a sorted array, so sort a copy first
        bubbleSort(arr, n);
        printf("(array sorted for binary search): ");
        for (int i = 0; i < n; i++) printf("%d ", arr[i]);
        printf("\n");
        result = binarySearch(arr, n, key);
    } else {
        printf("Invalid choice.\n");
        return 1;
    }

    if (result == -1) {
        printf("%d not found in the list.\n", key);
    } else {
        printf("%d found at index %d (position %d).\n", key, result, result + 1);
    }

    return 0;
}
