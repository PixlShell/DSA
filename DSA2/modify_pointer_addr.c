// Problem 4: Modifying Pointer Addresses within Functions
// Concept: Pass-by-reference using double pointers and realloc()

#include <stdio.h>    // For input/output functions
#include <stdlib.h>   // For malloc(), realloc(), free(), and exit()

// Function to reallocate memory for an array using double pointer
void reallocateArray(int **arr, int newSize) {
    *arr = (int *)realloc(*arr, newSize * sizeof(int));   // Reallocate memory to new size

    // Check if reallocation failed
    if (*arr == NULL) {
        printf("Memory reallocation failed!\n");
        exit(1);                                      // Exit program if memory allocation fails
    }
}

int main() {
    int n = 3;                                        // Initial array size
    int *arr = (int *)malloc(n * sizeof(int));        // Allocate memory for 'n' integers

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);                         // Input elements

    printf("Original array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);                        // Display original array
    printf("\n");

    int newSize;
    printf("Enter new size: ");
    scanf("%d", &newSize);                            // Input new array size

    reallocateArray(&arr, newSize);                   // Pass address of pointer for resizing

    printf("Enter new elements: ");
    for (int i = 0; i < newSize; i++)
        scanf("%d", &arr[i]);                         // Input new elements

    printf("Updated array: ");
    for (int i = 0; i < newSize; i++)
        printf("%d ", arr[i]);                        // Display updated array
    printf("\n");

    free(arr);                                        // Free allocated memory
    return 0;
}
