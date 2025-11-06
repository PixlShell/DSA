// Problem 3: 2D Dynamic Array Allocator
// Concept: Double pointers and dynamic memory allocation using malloc

#include <stdio.h>                                        // For input/output functions
#include <stdlib.h>                                       // For malloc() and free()

// Function to allocate memory for 2D array
int** allocateMatrix(int rows, int cols) {
    int **matrix = (int **)malloc(rows * sizeof(int *));  // Allocate memory for row pointers
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));    // Allocate memory for each row
    }
    return matrix;                                        // Return base address of 2D array
}

// Function to free allocated memory
void freeMatrix(int **matrix, int rows) {
    for (int i = 0; i < rows; i++)
        free(matrix[i]);                                  // Free each row
    free(matrix);                                         // Free row pointer array
}

int main() {
    int rows, cols;

    printf("Enter rows and columns: ");
    scanf("%d %d", &rows, &cols);                        // Input number of rows and columns

    int **mat = allocateMatrix(rows, cols);              // Create dynamic 2D array

    printf("Enter matrix elements:\n");
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            scanf("%d", &mat[i][j]);                     // Input matrix elements

    printf("You entered:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            printf("%d ", mat[i][j]);                   // Display matrix
        printf("\n");
    }

    freeMatrix(mat, rows);                              // Release allocated memory
    return 0;
}
