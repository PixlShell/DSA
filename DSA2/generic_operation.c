// Problem 5: Generic Operation Executor
// Concepts: Function pointers, callback mechanism

#include <stdio.h>   // For input and output functions

// Function definitions for basic arithmetic operations
int add (int a, int b) { return a + b; }               // Addition
int sub (int a, int b) { return a - b; }               // Subtraction
int mul (int a, int b) { return a * b; }               // Multiplication
int divi(int a, int b) { return b != 0 ? a / b : 0; }  // Division (with zero check)

int main() {
    int choice, a, b;

    // Array of function pointers for operations
    int (*operations[])(int, int) = { add, sub, mul, divi };

    // Input: user selects operation
    printf("Enter choice (0:Add, 1:Sub, 2:Mul, 3:Div): ");
    scanf("%d", &choice);

    // Input: two numbers for operation
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    // Perform operation based on user choice
    if (choice >= 0 && choice < 4)
        printf("Result = %d\n", operations[choice](a, b));
    else
        printf("Invalid choice!\n");

    return 0;
}
