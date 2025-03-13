#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to perform Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to perform Binary Search
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    
    while (low <= high) {
        int mid = (low + high) / 2;
        
        // Check if key is present at mid
        if (arr[mid] == key) {
            return mid;  // Element found at index mid
        }
        // If key is greater, ignore left half
        else if (arr[mid] < key) {
            low = mid + 1;
        }
        // If key is smaller, ignore right half
        else {
            high = mid - 1;
        }
    }
    
    return -1;  // Element not found
}

int main() {
    int n, key;

    // Initialize random number generator
    srand(time(0));

    // Get the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Generate random numbers
    int arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;  // Random numbers between 0 and 99
    }

    // Display the random numbers before sorting
    printf("Random numbers: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Apply Bubble Sort to the array
    bubbleSort(arr, n);

    // Display the sorted array
    printf("Sorted numbers: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Get the key to search for
    printf("Enter the key element to search for: ");
    scanf("%d", &key);

    // Perform Binary Search
    int result = binarySearch(arr, n, key);

    // Display the result
    if (result != -1) {
        printf("Element %d found at index %d\n", key, result);
    } else {
        printf("Element %d not found\n", key);
    }

    return 0;
}

