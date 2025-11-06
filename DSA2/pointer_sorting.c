// Problem 6: Function Pointer in Sorting
// Concepts: Comparator callbacks using qsort() and function pointers

#include <stdio.h>     
#include <stdlib.h>
#include <string.h>

int cmpInt(const void *a, const void *b) {                  // Comparator for integers
    return (*(int*)a - *(int*)b);                           // Ascending order
}

int cmpFloat(const void *a, const void *b) {                // Comparator for floats
    float diff = (*(float*)a - *(float*)b);                 
    return (diff > 0) - (diff < 0);                         // Returns 1, 0, or -1
}

int main() {
    int choice;                                              // Variable for menu choice

    printf("1. Sort Integers\n2. Sort Floats\nEnter choice: ");  // Display menu
    scanf("%d", &choice);                                    // Read user choice

    if (choice == 1) {                                       // Sort integers
        int arr[] = {5, 2, 8, 1, 3};                         // Integer array
        int n = 5;                                           // Number of elements
        qsort(arr, n, sizeof(int), cmpInt);                  // Call qsort() with int comparator
        printf("Sorted Integers: ");                         // Display sorted integers
        for (int i = 0; i < n; i++)                         
            printf("%d ", arr[i]);
    } 
    else if (choice == 2) {                                  // Sort floats
        float arr[] = {2.3, 0.9, 5.1, 1.4};                  // Float array
        int n = 4;                                           // Number of elements
        qsort(arr, n, sizeof(float), cmpFloat);              // Call qsort() with float comparator
        printf("Sorted Floats: ");                           // Display sorted floats
        for (int i = 0; i < n; i++)                         
            printf("%.2f ", arr[i]);
    } 
    else printf("Invalid choice!\n");                        // Invalid option check

    printf("\n");                                            // Line break
    return 0;                                                // End of program
}
