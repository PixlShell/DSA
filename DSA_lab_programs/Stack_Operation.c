#include <stdio.h>

#define Max_size 2                              // Stack size limit
int s[Max_size], top = -1;                      // s: stack array, top: stack pointer

void push(int data) {                           // Add element to top of stack
    if (top == Max_size - 1 ? (printf("Stack overflow\n")  , 1) : 0)  return;   // Check for overflow
    s[++top] = data;                            // Increment top and add element
}

void pop() {                                    // Remove element from top
    if (top == -1 ? (printf("Stack underflow\n"), 1): 0) return; // Check if stack is empty
    printf("Popped element is %d\n", s[top--]); // Print and decrement top
}

void display() {                                // Show all stack elements
    if (top == -1 ? (printf("Stack is empty\n"), 1): 0 ) return; // Check if stack is empty
    printf("Contents of the stack: \n");
    for (int i = 0; i <= top; ++i)              // Print from bottom to top
        printf("%d  ", s[i]);
    printf("\n");
}

int main() {                                    // Main menu driven program
    int ch = 0, data;                           // ch: choice, data: input element
    do {
        printf("\n1. Push 2. Pop 3. Display 4. Exit\nChoice: ");
        scanf("%d", &ch);
        
        if (ch == 1) {                          // Push operation
            printf("Enter element: ");
            scanf("%d", &data);
            push(data);
        }
        else if (ch == 2) pop();                // Pop operation
        else if (ch == 3) display();           // Display stack
        else if (ch == 4) return 0;            // Exit program
        else printf("Invalid choice\n");
    } while (ch != 4);
}