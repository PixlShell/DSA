// Problem 3: 2D Dynamic Array Allocator
// Concepts: Double pointers, dynamic allocation using malloc

#include <stdio.h>
#include <stdlib.h>

int** allocateMatrix(int rows, int cols) {             // Function to allocate 2D array
    int **matrix = (int **)malloc(rows * sizeof(int *));  // Allocate memory for row pointers
    for (int i = 0; i < rows; i++)                       // Loop through rows
        matrix[i] = (int *)malloc(cols * sizeof(int));    // Allocate each row
    return matrix;                                        // Return pointer to matrix
}

void freeMatrix(int **matrix, int rows) {                 // Function to free memory
    for (int i = 0; i < rows; i++)                       // Free each row
        free(matrix[i]);
    free(matrix);                                         // Free row pointer array
}

int main() {
    int rows, cols;                                       // Variables for matrix size
    printf("Enter rows and columns: ");                   // Prompt user input
    scanf("%d %d", &rows, &cols);                         // Read rows and columns

    int **mat = allocateMatrix(rows, cols);               // Allocate memory dynamically

    printf("Enter matrix elements:\n");                   // Input matrix elements
    for (int i = 0; i < rows; i++)                        // Loop for rows
        for (int j = 0; j < cols; j++)                    // Loop for columns
            scanf("%d", &mat[i][j]);                      // Read each element

    printf("You entered:\n");                             // Display entered matrix
    for (int i = 0; i < rows; i++) {                      // Row loop
        for (int j = 0; j < cols; j++)                    // Column loop
            printf("%d ", mat[i][j]);                     // Print element
        printf("\n");                                     // New line after each row
    }

    freeMatrix(mat, rows);                                // Free dynamically allocated memory
    return 0;                                             // End program
}
