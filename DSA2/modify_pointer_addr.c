// Problem 4: Modifying Pointer Addresses within Functions
// Concepts: Pass-by-reference using double pointers

#include <stdio.h>
#include <stdlib.h>

void reallocateArray(int **arr, int newSize) {              // Reallocate memory for array
    *arr = (int *)realloc(*arr, newSize * sizeof(int));     // Resize existing array
    if (*arr == NULL) {                                     // Check allocation failure
        printf("Memory reallocation failed!\n");
        exit(1);                                            // Exit if memory not allocated
    }
}

int main() {
    int n = 3;                                              // Initial array size
    int *arr = (int *)malloc(n * sizeof(int));              // Allocate memory

    printf("Enter %d elements: ", n);                       // Input elements
    for (int i = 0; i < n; i++)                             // Loop for input
        scanf("%d", &arr[i]);

    printf("Original array: ");                             // Display original array
    for (int i = 0; i < n; i++)                             // Loop to print
        printf("%d ", arr[i]);
    printf("\n");

    int newSize;                                            // New array size
    printf("Enter new size: ");                             // Input new size
    scanf("%d", &newSize);
    reallocateArray(&arr, newSize);                         // Pass address for reallocation

    printf("Enter new elements: ");                         // Input new elements
    for (int i = 0; i < newSize; i++)                       // Loop for input
        scanf("%d", &arr[i]);

    printf("Updated array: ");                              // Display updated array
    for (int i = 0; i < newSize; i++)                       // Loop to print
        printf("%d ", arr[i]);
    printf("\n");

    free(arr);                                              // Free allocated memory
    return 0;                                               // End program
}
