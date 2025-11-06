// Problem 13: Trace Bubble Sort Step-by-Step
// Concepts: Step tracing, iteration visualization, and time complexity understanding

#include <stdio.h>                           // For input/output functions

void printArray(int arr[], int n) {           // Function to print array elements
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void bubbleSortTrace(int arr[], int n) {      // Function to trace bubble sort steps
    for (int i = 0; i < n - 1; i++) {         
        printf("Pass %d: ", i + 1);           // Display pass number
        for (int j = 0; j < n - i - 1; j++) { // Compare adjacent elements
            if (arr[j] > arr[j + 1]) {        // Swap if elements are out of order
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        printArray(arr, n);                   // Print array after each pass
    }
}

int main() {
    int arr[] = {4, 3, 1, 2};                 // Input array
    int n = sizeof(arr) / sizeof(arr[0]);     // Number of elements

    printf("Initial Array: ");
    printArray(arr, n);                       // Display unsorted array

    bubbleSortTrace(arr, n);                  // Call trace function

    printf("Sorted Array: ");
    printArray(arr, n);                       // Display final sorted array

    return 0;                                 // End of program
}
