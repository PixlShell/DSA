// Problem 5: Generic Operation Executor
// Concepts: Function pointers, callback mechanism

#include <stdio.h>

int add(int a, int b) { return a + b; }                     // Addition function
int sub(int a, int b) { return a - b; }                     // Subtraction function
int mul(int a, int b) { return a * b; }                     // Multiplication function
int divi(int a, int b) { return b != 0 ? a / b : 0; }       // Division with zero check

int main() {
    int choice, a, b;                                       // Variables for input
    int (*operations[])(int, int) = {add, sub, mul, divi};  // Array of function pointers

    printf("Enter choice (0:Add, 1:Sub, 2:Mul, 3:Div): ");  // Menu for operations
    scanf("%d", &choice);                                   // Read user choice

    printf("Enter two numbers: ");                          // Input numbers
    scanf("%d %d", &a, &b);

    if (choice >= 0 && choice < 4)                          // Validate choice range
        printf("Result = %d\n", operations[choice](a, b));  // Call chosen function
    else
        printf("Invalid choice!\n");                        // Invalid operation

    return 0;                                               // End of program
}
