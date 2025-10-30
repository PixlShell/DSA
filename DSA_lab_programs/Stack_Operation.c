#include <stdio.h>

#define Max_size 2                          /* Stack size limit */
int s[Max_size], top = -1;                  /* s: stack array, top: stack pointer */

void push(int data){                        /* Add element to top of stack */
    if (top == Max_size - 1){              /* Check if stack is full */
        printf("Stack overflow\n");
        return;
    }
    s[++top] = data;                       /* Increment top and add element */
}

void pop() {                               /* Remove element from top */
    if (top == -1){                        /* Check if stack is empty */
        printf("Stack underflow\n");
        return;
    }
    printf("Popped element is %d\n", s[top]);
    --top;                                 /* Decrement top to remove element */
}

void display(){                            /* Show all stack elements */
    if (top == -1){                        /* Check if stack is empty */
        printf("Stack is empty\n");
        return;
    }
    printf("Contents of the stack: \n");
    for (int i = 0; i <= top; ++i)         /* Print from bottom to top */
        printf("%d  ", s[i]);
    printf("\n");
}

int main(){                                /* Main menu driven program */
    int ch = 0, data;                      /* ch: choice, data: input element */
    do {
        printf("\n1. Push 2. Pop 3. Display 4. Exit\n");
        printf("Enter the choice: ");
        scanf("%d", &ch);
        if(ch == 1) {                      /* Push operation */
            printf("Enter element: ");
            scanf("%d", &data);
            push(data);
        } 
        else if(ch == 2) pop();            /* Pop operation */
        else if(ch == 3) display();        /* Display stack */
        else if(ch == 4) return 0;         /* Exit program */
        else printf("Invalid choice\n");
    } while(ch != 4);
}