#include <stdio.h>

#define MAX_SIZE 5                           // Queue size
int f = -1, r = -1, q[MAX_SIZE];            // f: front, r: rear, q: queue array

void insert(int data){                       // Insert element at rear
    if(r == MAX_SIZE - 1 ? (printf("OVERFLOW!!!\n"), 1): 0) return;  // Check if queue is full
    if(f == -1)  f = 0;                            // If first element
    q[++r] = data;                          // Add element and move rear
}

void delete(){                               // Delete element from front
    if (f == -1 || f > r){                  // Check empty or invalid state
        printf("UNDERFLOW!!!\n");
        f = r = -1;                         // Reset queue state
        return;
    }
    printf("Item deleted = %d\n", q[f++]);  // Remove and move front
}

void display(){                              // Show all queue elements
    if (f == -1 ? (printf("UNDERFLOW!!!\n"), 1) : 0 ) return ; // Check if queue is empty
    printf("The elements are: \n");
    for (int i = f; i <= r; i++)            // Print from front to rear
        printf("%d ", q[i]);
}

int main(){
    int ch = 0, data;                       // ch: choice, data: input element
    do {                                    // Menu driven program
        printf("\n\n1. Insert 2. Delete 3. Display 4. Exit\nChoice: ");
        scanf("%d", &ch);
        if(ch == 1) {                       // Insert operation
            printf("Enter element: ");
            scanf("%d", &data);
            insert(data);
        } 
        else if(ch == 2) delete();          // Delete operation
        else if(ch == 3) display();         // Display queue
        else if(ch == 4) return 0;          // Exit program
        else printf("Invalid choice\n");
    } while(ch != 4);
}