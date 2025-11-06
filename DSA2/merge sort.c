// Problem 11: Merge Sort Implementation
// Concepts: Divide and Conquer, Recursion

#include <stdio.h>                            // For input/output functions

int recursiveCalls = 0;                       // Counter to track recursive calls

void merge(int arr[], int l, int m, int r) {  // Function to merge two sorted halves
    int n1 = m - l + 1;                       // Size of left subarray
    int n2 = r - m;                           // Size of right subarray
    int L[n1], R[n2];                         // Temporary arrays

    for (int i = 0; i < n1; i++)              
        L[i] = arr[l + i];                    // Copy elements to left array
    for (int j = 0; j < n2; j++)              
        R[j] = arr[m + 1 + j];                // Copy elements to right array

    int i = 0, j = 0, k = l;                  // Initialize pointers
    while (i < n1 && j < n2) {                
        if (L[i] <= R[j])                     
            arr[k++] = L[i++];                // Place smaller element
        else                                  
            arr[k++] = R[j++];                // Place right element
    }
    while (i < n1) arr[k++] = L[i++];         // Copy remaining left elements
    while (j < n2) arr[k++] = R[j++];         // Copy remaining right elements
}

void mergeSort(int arr[], int l, int r) {     // Recursive merge sort function
    recursiveCalls++;                         // Count each recursive call
    if (l < r) {                              // Base condition
        int m = (l + r) / 2;                  // Find middle point
        mergeSort(arr, l, m);                 // Sort first half
        mergeSort(arr, m + 1, r);             // Sort second half
        merge(arr, l, m, r);                  // Merge both halves
    }
}

void printArray(int arr[], int n) {           // Function to print array elements
    for (int i = 0; i < n; i++)               
        printf("%d ", arr[i]);                
    printf("\n");                             
}

int main() {
    int arr[] = {5, 3, 8, 2, 1};              // Input array
    int n = sizeof(arr) / sizeof(arr[0]);     // Calculate number of elements

    printf("Original Array: ");               
    printArray(arr, n);                       // Display unsorted array

    mergeSort(arr, 0, n - 1);                 // Perform merge sort

    printf("Sorted Array: ");                 
    printArray(arr, n);                       // Display sorted array
    printf("Total recursive calls = %d\n", recursiveCalls);  // Show recursion count

    return 0;                                 // End of program
}
