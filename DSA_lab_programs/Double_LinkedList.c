#include <stdio.h>
#include <stdlib.h>

typedef struct node {                      // doubly linked list node
    int data;                              // stored value
    struct node *prev;                     // pointer to previous node
    struct node *next;                     // pointer to next node
} Node;
Node *head = NULL;                         // head (start) of the list

Node* newNode(int data) {                  // allocate and initialize node
    Node *n = (Node*)malloc(sizeof(Node)); // allocate memory
    if (!n) {                              // allocation check
        printf("Memory allocation failed!\n");
        exit(1);
    }
    n->data = data; n->prev = n->next = NULL; // set fields
    return n;
}

void insertFront(int data) {               // insert node at front
    Node *n = newNode(data);               // create node
    if (!head) {                           // empty list
        head = n;                          // new node is head
    } else {
        n->next = head;                    // link new node before head
        head->prev = n;                    // update previous head
        head = n;                          // update head pointer
    }
}

void insertLast(int data) {                // insert node at end
    Node *n = newNode(data);               // create node
    if (!head) {                           // empty list
        head = n;                          // new node becomes head
    } else {
        Node *temp = head;                 // traverse to last node
        while (temp->next)
            temp = temp->next;
        temp->next = n;                    // append node
        n->prev = temp;                    // link back pointer
    }
}

void deleteFront() {                       // remove node from front
    if (!head ? (printf("List is empty!\n"), 1) : 0 ) return;     // empty list
    Node *temp = head;                     // node to delete
    printf("Deleted element is: %d\n", temp->data);
    head = head->next;                     // move head forward
    if (head) head->prev = NULL;           // clear previous pointer
    free(temp);                            // free removed node
}

void deleteLast() {                        // remove node from end
    if (!head ? (printf("List is empty!\n"), 1) : 0 ) return;     // empty list
    if (!head->next) {                     // single node
        printf("Deleted element is: %d\n", head->data);
        free(head); head = NULL;           // free and clear head
        return;
    }
    Node *temp = head;                      // traverse to last node
    while (temp->next)
        temp = temp->next;
    printf("Deleted element is: %d\n", temp->data);
    temp->prev->next = NULL;               // unlink last node
    free(temp);                            // free it
}

void display() {                           // display list contents
    if (!head ? (printf("List is empty!\n"), 1) : 0 ) return;     // empty list
    Node *temp = head;                     // iterate from head
    printf("List elements :\n");
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {                            
    int ch, data;
    do {
        printf("\n1. Insert Front\n2. Insert Rear\n3. Delete Front\n4. Delete Rear\n5. Display\n6. Exit\nChoice");
        scanf("%d", &ch);
        if (ch == 1) {
            printf("Enter element to insert at front: ");
            scanf("%d", &data);
            insertFront(data);
        } else if (ch == 2) {
            printf("Enter element to insert at rear: ");
            scanf("%d", &data);
            insertLast(data);
        } 
        else if (ch == 3) deleteFront();
        else if (ch == 4) deleteLast();
        else if (ch == 5) display();
        else if (ch == 6) return 0;
        else printf("Invalid choice!\n");
    } while (ch != 6);
}
