#include <stdio.h>

#define MAX 5
int q[MAX], f = -1, r = -1;

int isFull() { return (f == 0 && r == MAX - 1) || (f == r + 1); }
int isEmpty() { return f == -1; }

void insert(int data) {
    if (isFull() ? (printf("Queue Full!\n"), 1) : 0) return;
    if (isEmpty()) {
        f = r = 0;
        q[r] = data;
        return;
    }
    r = (r + 1) % MAX;
    int i = r;
    int prev = (i - 1 + MAX) % MAX;

    while (i != f && q[prev] < data) {
        q[i] = q[prev];
        i = prev;
        prev = (prev - 1 + MAX) % MAX;
    }
    q[i] = data;
}

void delete() {
    if ( isEmpty() ? (printf("Queue Empty!\n"), 1) : 0) return;
    printf("Deleted: %d\n", q[f]);
    (f == r) ? (f = r = -1) : (f = (f + 1) % MAX);
}

void display() {
    if ( isEmpty() ? (printf("Queue Empty!\n"), 1) : 0) return;
    printf("Queue Elements: ");
    int i = f;
    do {
        printf("%d ", q[i]);
        i = (i + 1) % MAX;
    } while (i != (r + 1) % MAX);
    printf("\n");
}

int main() {
    int ch = 0, data;
    do {
        printf("\n1. Insert 2. Delete 3. Display 4. Exit\nChoice:");
        scanf("%d", &ch);
        if (ch == 1) {
            printf("Enter data: ");
            scanf("%d", &data);
            insert(data);
        }
        else if (ch == 2) delete();
        else if (ch == 3) display();
        else if (ch == 4) return 0;
        else printf("Invalid choice!\n");
    } while (ch != 4);
}
