#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int arr[], int n, int *operationCount, double *timeTaken) {
    clock_t start, end;
    start = clock();

    int temp;
    *operationCount = 0;

    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            (*operationCount)++; 
            if (arr[j] > arr[j+1]) {
                // Swap the elements
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                (*operationCount)++; 
            }
        }
    }

    end = clock();
    *timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;
}


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
   
    srand(time(NULL));

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
    }

    printf("Generated Random Array:\n");
    printArray(arr, n);

    int operationCount = 0;
    double timeTaken;

    bubbleSort(arr, n, &operationCount, &timeTaken);

    printf("\nSorted Array:\n");
    printArray(arr, n);

    printf("\nTime taken for sorting: %f seconds\n", timeTaken);
    printf("Number of basic operations (comparisons and swaps): %d\n", operationCount);

    return 0;
}

