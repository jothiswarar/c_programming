#include <stdio.h>
#include <stdlib.h>

#define ORDER 5

// Node structure
typedef struct Node {
    int keys[ORDER - 1];
    struct Node *children[ORDER];
    int keyCount;
    int isLeaf;
} Node;

// Function to create a new node
Node *createNode() {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->keyCount = 0;
    newNode->isLeaf = 1;
    for (int i = 0; i < ORDER; i++) {
        newNode->children[i] = NULL;
    }
    return newNode;
}

// Function to split a child of a node
void splitChild(Node *parent, int index, Node *child) {
    Node *newChild = createNode();
    newChild->isLeaf = child->isLeaf;
    newChild->keyCount = (ORDER - 1) / 2;

    // Move keys and children to the new child
    for (int i = 0; i < (ORDER - 1) / 2; i++) {
        newChild->keys[i] = child->keys[i + (ORDER + 1) / 2];
        newChild->children[i] = child->children[i + (ORDER + 1) / 2];
    }
    newChild->children[(ORDER - 1) / 2] = child->children[ORDER - 1];

    child->keyCount = (ORDER - 1) / 2;

    // Move the middle key and link to the parent
    for (int i = parent->keyCount; i > index; i--) {
        parent->keys[i] = parent->keys[i - 1];
        parent->children[i + 1] = parent->children[i];
    }
    parent->keys[index] = child->keys[(ORDER - 1) / 2];
    parent->children[index + 1] = newChild;

    parent->keyCount++;
}

// Function to insert a key into the B-tree
Node *insert(Node *root, int key) {
    if (!root) {
        Node *newRoot = createNode();
        newRoot->keys[0] = key;
        newRoot->keyCount = 1;
        return newRoot;
    }

    if (root->keyCount == ORDER - 1) {
        Node *newRoot = createNode();
        newRoot->isLeaf = 0;
        newRoot->children[0] = root;
        splitChild(newRoot, 0, root);
        root = newRoot;
    }

    int i = root->keyCount - 1;

    while (i >= 0 && key < root->keys[i]) {
        root->keys[i + 1] = root->keys[i];
        i--;
    }

    root->keys[i + 1] = key;
    root->keyCount++;

    return root;
}

// Function to print the B-tree
void printTree(Node *root) {
    if (root) {
        for (int i = 0; i < root->keyCount; i++) {
            printTree(root->children[i]);
            printf("%d ", root->keys[i]);
        }
        printTree(root->children[root->keyCount]);
    }
}

int main() {
    Node *root = NULL;

    // Insert keys into the B-tree
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 12);
    root = insert(root, 30);
    root = insert(root, 7);
    root = insert(root, 17);

    // Print the B-tree
    printf("B-tree: ");
    printTree(root);

    return 0;
}
