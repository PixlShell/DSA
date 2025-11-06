// Problem 6: Function Pointer in Sorting
// Concepts: Comparator callbacks using qsort() and function pointers

#include <stdio.h>      // For input/output functions
#include <stdlib.h>     // For qsort() and standard library functions
#include <string.h>     // For memory operations (not used but commonly included)

// Comparator function for integers
int cmpInt(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);                  // Ascending order
}

// Comparator function for floats
int cmpFloat(const void *a, const void *b) {
    float diff = (*(float*)a - *(float*)b);
    return (diff > 0) - (diff < 0);               // Returns 1, 0, or -1
}

int main() {
    int choice;

    // Ask user to choose data type for sorting
    printf("1. Sort Integers\n2. Sort Floats\nEnter choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        // Integer array
        int arr[] = {5, 2, 8, 1, 3};
        int n = 5;

        // Sort integers using qsort() with cmpInt as comparator
        qsort(arr, n, sizeof(int), cmpInt);

        // Display sorted integers
        printf("Sorted Integers: ");
        for (int i = 0; i < n; i++)
            printf("%d ", arr[i]);
    } 
    else {
        // Float array
        float arr[] = {2.3, 0.9, 5.1, 1.4};
        int n = 4;

        // Sort floats using qsort() with cmpFloat as comparator
        qsort(arr, n, sizeof(float), cmpFloat);

        // Display sorted floats
        printf("Sorted Floats: ");
        for (int i = 0; i < n; i++)
            printf("%.2f ", arr[i]);
    }

    printf("\n");
    return 0;
}
