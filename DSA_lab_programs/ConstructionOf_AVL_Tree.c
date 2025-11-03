#include <stdio.h>
#include <stdlib.h>

struct Node {
    int jointID, angle, height;                                         // Node data
    struct Node *left, *right;                                          // Left and right children
};

int height(struct Node* n) { return n ? n->height : 0; }                // Get height of node
int max(int a, int b) { return (a > b) ? a : b; }                       // Return maximum of two

struct Node* newNode(int id, int ang) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));      // Allocate new node
    node->jointID = id;                                                 // Set JointID
    node->angle = ang;                                                  // Set Angle
    node->left = node->right = NULL;                                    // Initialize children
    node->height = 1;                                                   // Height of new node
    return node;
}

struct Node* rightRotate(struct Node* y) {
    struct Node* x = y->left;                                           // Left child
    struct Node* T2 = x->right;                                         // Right subtree of x
    x->right = y;                                                       // Perform rotation
    y->left = T2;                                                       // Reattach subtree
    y->height = max(height(y->left), height(y->right)) + 1;             // Update height
    x->height = max(height(x->left), height(x->right)) + 1;             // Update height
    printf("AVL Tree balanced using Right Rotation at node %d\n", y->jointID);
    return x;                                                           // Return new root
}

struct Node* leftRotate(struct Node* x) {
    struct Node* y = x->right;                                          // Right child
    struct Node* T2 = y->left;                                          // Left subtree of y
    y->left = x;                                                        // Perform rotation
    x->right = T2;                                                      // Reattach subtree
    x->height = max(height(x->left), height(x->right)) + 1;             // Update height
    y->height = max(height(y->left), height(y->right)) + 1;             // Update height
    printf("AVL Tree balanced using Left Rotation at node %d\n", x->jointID);
    return y;                                                           // Return new root
}

int getBalance(struct Node* n) { return n ? height(n->left) - height(n->right) : 0; }  // Balance factor

struct Node* insert(struct Node* node, int id, int ang) {
    if (node == NULL) return newNode(id, ang);                          // Insert new node

    if (id < node->jointID) node->left = insert(node->left, id, ang);   // Insert left
    else if (id > node->jointID) node->right = insert(node->right, id, ang); // Insert right
    else return node;                                                   // Duplicate not allowed

    node->height = 1 + max(height(node->left), height(node->right));    // Update height
    int balance = getBalance(node);                                     // Check balance

    if (balance > 1 && id < node->left->jointID)                        // LL case
        return rightRotate(node);
    if (balance < -1 && id > node->right->jointID)                      // RR case
        return leftRotate(node);
    if (balance > 1 && id > node->left->jointID) {                      // LR case
        node->left = leftRotate(node->left);
        printf("AVL Tree balanced using Left-Right Rotation at node %d\n", node->jointID);
        return rightRotate(node);
    }
    if (balance < -1 && id < node->right->jointID) {                    // RL case
        node->right = rightRotate(node->right);
        printf("AVL Tree balanced using Right-Left Rotation at node %d\n", node->jointID);
        return leftRotate(node);
    }
    return node;                                                        // Return balanced node
}

void inorder(struct Node* root) {
    if (root) {
        inorder(root->left);                                            // Visit left
        printf("JointID: %d -> Angle: %d\n", root->jointID, root->angle); // Print node
        inorder(root->right);                                           // Visit right
    }
}

int main() {
    struct Node* root = NULL;                                           // Root pointer
    int n, id, ang;                                                     // Variables
    printf("Enter number of joints: ");
    scanf("%d", &n);                                                    // Input number
    printf("Enter (JointID, Angle) pairs:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &id, &ang);                                      // Read data
        root = insert(root, id, ang);                                   // Insert into AVL tree
    }
    printf("\nInorder Traversal (JointID -> Angle):\n");
    inorder(root);                                                      // Display sorted output
    return 0;
}
