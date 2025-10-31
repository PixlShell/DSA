#include <stdio.h>

#define MAX 5                              // Size of circular queue
int q[MAX], f = -1, r = -1;               // q: queue array, f: front, r: rear

int isFull() {                            // Check if queue is full
    return (f == 0 && r == MAX-1) || (f == r+1); 
}
int isEmpty() { return f == -1; }         // Check if queue is empty

void insert(int data) {                   // Add element at rear
    if( isFull() ? (printf("Queue Full"), 1) : 0) return ;
    if( isEmpty() ) f = 0;                // Initialize front for first element
    r = (r + 1) % MAX;                    // Move rear circularly
    q[r] = data;                          // Store new element
}

void delete() {                           // Remove element from front
    if( isEmpty() ? ( printf("Queue Empty!\n"), 1) : 0 ) return;
    printf("Deleted: %d\n", q[f]);        // Show deleted element
    (f == r) ? (f = r = -1) : (f = (f + 1) % MAX);               
}

void display() {                          // Show all queue elements
    if( isEmpty() ? (printf("Queue Empty!\n"), 1) : 0) return;
    printf("Queue Elements: ");            // Print elements in order
    int i = f;                            // Start from front
    do {
        printf("%d ", q[i]);              // Print current element
        i = (i + 1) % MAX;                // Move to next position
    } while(i != (r + 1) % MAX);          // Until we reach back to front
    printf("\n");
}

int main() {                              // Menu driven program
    int ch = 0, data;                     // ch: choice, data: input value
    do {                                  // Continuous operation loop
        printf("\n1. Insert 2. Delete 3. Display 4. Exit\nChoice:");
        scanf("%d", &ch);                 // Get user's choice
        if(ch == 1) {                     // Insert operation
            printf("Enter data: ");
            scanf("%d", &data);
            insert(data);
        }
        else if(ch == 2) delete();        // Delete operation
        else if(ch == 3) display();       // Display operation
        else if(ch == 4) return 0;        // Exit program
        else printf("Invalid choice!\n");  // Handle invalid input
    } while(ch != 4);
}
