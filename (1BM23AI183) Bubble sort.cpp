#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Bubble sort function with time and operation count tracking
void bubbleSort(int arr[], int n, int *operationCount, double *timeTaken) {
    clock_t start, end;
    start = clock();

    int temp;
    *operationCount = 0; // Initialize operation count

    // Bubble Sort Algorithm
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            (*operationCount)++; // Increment operation count for comparison
            if (arr[j] > arr[j+1]) {
                // Swap the elements
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                (*operationCount)++; // Increment operation count for swap
            }
        }
    }

    end = clock();
    *timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    // Seed for random number generation
    srand(time(NULL));

    // Generate random numbers and store them in the array
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000; // Random number between 0 and 999
    }

    printf("Generated Random Array:\n");
    printArray(arr, n);

    int operationCount = 0;
    double timeTaken;

    // Call bubbleSort and track the time taken and operations count
    bubbleSort(arr, n, &operationCount, &timeTaken);

    printf("\nSorted Array:\n");
    printArray(arr, n);

    printf("\nTime taken for sorting: %f seconds\n", timeTaken);
    printf("Number of basic operations (comparisons and swaps): %d\n", operationCount);

    return 0;
}

