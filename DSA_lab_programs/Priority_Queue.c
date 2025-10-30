#include <stdio.h>
#include <stdlib.h>

typedef struct node {                    // Node structure for priority queue
    int data;                            // Priority value
    struct node *next;                   // Link to next node
} Node;

Node *front = NULL;                       // Front pointer (highest priority)

Node* newNode(int data) {                // Create new node with priority
    Node *n = (Node*)malloc(sizeof(Node)); // Allocate memory
    if (!n) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    n->data = data;                      // Set priority value
    n->next = NULL;                      // Initialize link
    return n;
}

void insert(int data) {                  // Insert with priority order
    Node *n = newNode(data);             // Create new node

    if (!front || data >= front->data) { // Empty or highest priority
        n->next = front;                 // New node becomes front
        front = n;
    } else {
        Node *temp = front;              // Find insertion position
        while (temp->next && temp->next->data > data)  // Traverse to right spot
            temp = temp->next;
        n->next = temp->next;            // Insert node in position
        temp->next = n;
    }

    printf("Element inserted successfully!\n");
}

void delete() {                          // Remove highest priority
    if (!front) {
        printf("Underflow!\n");          // Check if empty
        return;
    }

    Node *temp = front;                  // Save front node
    printf("Deleted element is: %d\n", temp->data);
    front = front->next;                 // Update front
    free(temp);                          // Free memory
}

void display() {                         // Show all elements
    if (!front) {
        printf("Queue is empty!\n");      // Check if empty
        return;
    }
    Node *temp = front;                  // Start from front
    printf("Queue elements are:\n");      // Print in priority order
    while (temp) {
        printf("%d ", temp->data);       // Show priority value
        temp = temp->next;
    }
    printf("\n");
}


int main() {                             // Menu driven program
    int ch, data;                        // Choice and priority value
    do {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");    // Get user input
        scanf("%d", &ch);

        if (ch == 1) {                   // Insert operation
            printf("Enter the element to be inserted: ");
            scanf("%d", &data);
            insert(data);
        } 
        else if (ch == 2) delete();      // Delete highest priority
        else if (ch == 3) display();     // Show queue
        else if (ch == 4) return 0;      // Exit program
        else printf("Invalid choice!\n"); // Invalid input
    } while (ch != 4);
}
