// Problem 10: Bubble Sort vs Selection Sort
// Concepts: Sorting logic, stability, comparison of swap counts

#include <stdio.h>                                           // For input/output functions

void bubbleSort(int arr[], int n, int *swapCount) {          // Bubble sort implementation
    *swapCount = 0;                                          // Initialize swap counter
    for (int i = 0; i < n - 1; i++) {                       
        for (int j = 0; j < n - i - 1; j++) {               
            if (arr[j] > arr[j + 1]) {                       // Compare adjacent elements
                int temp = arr[j];                           
                arr[j] = arr[j + 1];                         
                arr[j + 1] = temp;                           
                (*swapCount)++;                              // Increment swap count
            }
        }
    }
}

void selectionSort(int arr[], int n, int *swapCount) {       // Selection sort implementation
    *swapCount = 0;                                          // Initialize swap counter
    for (int i = 0; i < n - 1; i++) {                       
        int min = i;                                         // Assume current as minimum
        for (int j = i + 1; j < n; j++) {                   
            if (arr[j] < arr[min])                          
                min = j;                                     // Update minimum index
        }
        if (min != i) {                                      // Swap if needed
            int temp = arr[i];                              
            arr[i] = arr[min];                              
            arr[min] = temp;                                
            (*swapCount)++;                                  // Increment swap count
        }
    }
}

void printArray(int arr[], int n) {                          // Function to print array
    for (int i = 0; i < n; i++)                             
        printf("%d ", arr[i]);                              
    printf("\n");                                           
}

int main() {
    int arr1[] = {5, 1, 4, 2, 8};                           // Input array for bubble sort
    int arr2[] = {5, 1, 4, 2, 8};                           // Copy for selection sort
    int n = 5, swapB, swapS;                                // Variables for swap counts

    bubbleSort(arr1, n, &swapB);                            // Perform bubble sort
    selectionSort(arr2, n, &swapS);                         // Perform selection sort

    printf("Bubble Sorted: ");                              
    printArray(arr1, n);                                    // Display bubble sorted array
    printf("Selection Sorted: ");                           
    printArray(arr2, n);                                    // Display selection sorted array

    printf("Bubble Sort Swaps: %d\n", swapB);               // Show bubble sort swap count
    printf("Selection Sort Swaps: %d\n", swapS);            // Show selection sort swap count

    return 0;                                               // End of program
}
