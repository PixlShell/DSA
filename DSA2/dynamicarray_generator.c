// Problem 7: Dynamic Array Generator
// Concepts: Returning dynamically allocated arrays using malloc()

#include <stdio.h>       
#include <stdlib.h>    

int* createArray(int n) {                               // Function to create dynamic array
    int *arr = (int*)malloc(n * sizeof(int));           // Allocate memory for n integers
    if (arr == NULL) {                                  // Check if allocation failed
        printf("Memory allocation failed!\n");
        exit(1);                                        // Exit program on failure
    }

    for (int i = 0; i < n; i++)                        
        arr[i] = i * i;                                 // Initialize elements as i*i

    return arr;                                         // Return pointer to allocated array
}

int main() {
    int n;                                              // Variable for size of array
    printf("Enter number of elements: ");               
    scanf("%d", &n);                                    // Input array size

    int *array = createArray(n);                        // Call function to create array

    printf("Generated array: ");                        
    for (int i = 0; i < n; i++)                        
        printf("%d ", array[i]);                        // Print array elements
    printf("\n");                                       

    free(array);                                        // Free allocated memory
    return 0;                                           // End of program
}
