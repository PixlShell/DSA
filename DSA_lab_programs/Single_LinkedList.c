#include <stdio.h>
#include <stdlib.h>

typedef struct node {                      // single list node
    int data;                              // stored value
    struct node *next;                     // pointer to next node
} Node;

Node *head = NULL;                         // head of the list

Node* newNode(int data) {                 // allocate and init node
    Node *n = (Node*)malloc(sizeof(Node)); // allocate memory for node
    if (!n) {                              // check allocation
        printf("Memory allocation failed!\n");
        exit(1);
    }
    n->data = data; n->next = NULL;       // set fields
    return n;
}

void insertFront(int data) {               // insert at beginning
    Node *n = newNode(data);               // create node
    n->next = head;                        // link to current head
    head = n;                              // update head
}

void insertLast(int data) {                // insert at end
    Node *n = newNode(data);               // create node
    if (!head) {                           // empty list
        head = n; return;                  // new node is head; done
    } 
    Node *temp = head;                     // traverse to last
    while (temp->next)                     // move until last node
        temp = temp->next;
    temp->next = n;                        // append new node
}

void deleteFront() {                       // remove from beginning
    if (!head) {                           // empty check
        printf("List is empty!\n");
        return;
    }
    Node *temp = head;                     // node to delete
    printf("Deleted element is: %d\n", temp->data);
    head = head->next;                     // move head forward
    free(temp);                            // free memory
}

void deleteLast() {                        // remove from end
    if (!head) {                           // empty list
        printf("List is empty!\n");
        return;
    }
    if (!head->next) {                     // single node case
        printf("Deleted element is: %d\n", head->data);
        free(head);
        head = NULL;
        return;
    }
    Node *temp = head;                      // find second-last
    while (temp->next->next)               // stop at second-last
        temp = temp->next;
    printf("Deleted element is: %d\n", temp->next->data);
    free(temp->next);                      // free last node
    temp->next = NULL;                     // terminate list
}

void display() {                           // print list contents
    if (!head) {                           // empty check
        printf("List is empty!\n");
        return;
    }
    Node *temp = head;                     // iterate from head
    printf("List elements are:\n");
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {                               // menu driven driver
    int ch, data;
    do {
        printf("\n1. Insert Front\n2. Insert Rear\n3. Delete Front\n4. Delete Rear\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        if (ch == 1) {                      // insert at front
            printf("Enter element to insert at front: ");
            scanf("%d", &data);
            insertFront(data);
        } 
        else if (ch == 2) {                 // insert at rear
            printf("Enter element to insert at rear: ");
            scanf("%d", &data);
            insertLast(data);
        } 
        else if (ch == 3) deleteFront();    // delete front
        else if (ch == 4) deleteLast();     // delete last
        else if (ch == 5) display();        // display list
        else if (ch == 6) return 0;         // exit
        else printf("Invalid choice!\n");
    } while (ch != 6);
}
