#include <stdio.h>
#include <stdlib.h>

typedef struct node {                     // Node structure for deque
    int data;                            // Store element value
    struct node *next;                   // Link to next node
} Node;
Node *front = NULL, *rear = NULL;         // Front and rear pointers

Node* newNode(int value) {               // Create new node with given value
    Node *n = malloc(sizeof(Node));      // Allocate memory
    if (!n ? (printf("Memory allocation failed!\n"), 1) : 0 ) exit(1); // Check allocation
    n->data = value; n->next = NULL;     // Initialize node data
    return n;
}

void insertFront(int data) {             // Add node at front
    Node *n = newNode(data);             // Create new node
    n->next = front;                     // Link to current front
    front = n;                           // Update front pointer
    if (!rear) rear = n;                 // If first node
}

void insertLast(int data) {              // Add node at rear
    Node *n = newNode(data);             // Create new node
    (!rear) ? (front = rear = n) : (rear = rear->next = n); // Link at end
}      

void deleteFront() {                     // Remove front node
    if (!front ? (printf("Queue is empty!\n"), 1) : 0 ) return;// Check if empty
    Node *t = front;                     // Save front node
    front = front->next;                 // Move front ahead
    if (!front) rear = NULL;             // If last node
    free(t);                            // Free memory
}

void deleteLast() {                      // Remove rear node
    if (!rear ? (printf("Queue is empty!\n"), 1) : 0 ) return;// Check if empty
    if (front == rear) {                 // If single node
        free(front); 
        front = rear = NULL; 
        return; 
    }
    Node *t = front;                     // Find node before rear
    while (t->next != rear) 
        t = t->next;
    free(rear);                         // Free rear node
    rear = t;                           // Update rear
    rear->next = NULL;                  // Set new end
}

void display() {                         // Show all elements
    if (!front ? (printf("Queue is empty!\n"), 1) : 0 ) return;// Check if empty
    printf("Queue elements: ");           // Print all nodes
    for (Node *p = front; p; p = p->next) 
        printf("%d ", p->data);
}

int main() {                             // Menu driven program
    int ch, data;                        // Choice and input vars
    do {
        printf("\n\n1.Insert Front\n2.Insert Last\n3.Delete Front\n4.Delete Last\n5.Display\n6.Exit\nChoice:");
        scanf("%d", &ch);
        if (ch == 1) {                   // Insert at front
            printf("Enter data: ");
            scanf("%d", &data);
            insertFront(data);
        }
        else if (ch == 2) {              // Insert at rear
            printf("Enter data: ");
            scanf("%d", &data);
            insertLast(data);
        }
        else if (ch == 3) deleteFront(); // Delete from front
        else if (ch == 4) deleteLast();  // Delete from rear
        else if (ch == 5) display();     // Show queue
        else if (ch == 6) return 0;      // Exit program
        else printf("Invalid choice!\n"); // Invalid input
    } while (ch != 6);
}
