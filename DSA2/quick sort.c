// Problem 12: Quick Sort Implementation
// Concepts: Partitioning, Recursion, Randomized Pivot

#include <stdio.h>                              // For input/output functions
#include <stdlib.h>                             // For rand(), srand()
#include <time.h>                               // For seeding random pivot

void swap(int *a, int *b) {                     // Function to swap two elements
    int temp = *a; 
    *a = *b; 
    *b = temp;
}

int partition(int arr[], int low, int high) {   // Function to partition array
    int pivotIndex = low + rand() % (high - low + 1); // Random pivot index
    int pivot = arr[pivotIndex];                // Select pivot element
    swap(&arr[pivotIndex], &arr[high]);         // Move pivot to end

    int i = (low - 1);                          
    for (int j = low; j < high; j++) {          // Rearrange elements
        if (arr[j] < pivot) {                   
            i++;                                
            swap(&arr[i], &arr[j]);             // Place smaller elements left
        }
    }
    swap(&arr[i + 1], &arr[high]);              // Place pivot in correct position
    return (i + 1);                             // Return partition index
}

void quickSort(int arr[], int low, int high) {  // Recursive quick sort function
    if (low < high) {                           
        int pi = partition(arr, low, high);     // Get pivot position
        quickSort(arr, low, pi - 1);            // Sort left subarray
        quickSort(arr, pi + 1, high);           // Sort right subarray
    }
}

void printArray(int arr[], int n) {             // Function to display array
    for (int i = 0; i < n; i++)                 
        printf("%d ", arr[i]);                  
    printf("\n");                               
}

int main() {
    srand(time(0));                             // Seed for random pivot
    int arr[] = {9, 4, 8, 3, 1, 2, 5};          // Input array
    int n = sizeof(arr) / sizeof(arr[0]);       // Calculate number of elements

    printf("Original Array: ");                 
    printArray(arr, n);                         // Display unsorted array

    quickSort(arr, 0, n - 1);                   // Perform quick sort

    printf("Sorted Array: ");                   
    printArray(arr, n);                         // Display sorted array

    return 0;                                   // End of program
}
