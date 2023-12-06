#include <stdio.h>
#include <stdlib.h>

#define ORDER 3

typedef struct Node {
    int keys[ORDER - 1];
    struct Node *children[ORDER];
    int numKeys;
    int isLeaf;
} Node;

Node *createNode() {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->numKeys = 0;
    newNode->isLeaf = 1;
    for (int i = 0; i < ORDER; i++) {
        newNode->children[i] = NULL;
    }
    return newNode;
}

void splitChild(Node *parent, int index) {
    Node *newChild = createNode();
    Node *splitNode = parent->children[index];
    newChild->isLeaf = splitNode->isLeaf;
    newChild->numKeys = ORDER / 2 - 1;

    for (int i = 0; i < ORDER / 2 - 1; i++) {
        newChild->keys[i] = splitNode->keys[i + ORDER / 2];
    }

    if (!splitNode->isLeaf) {
        for (int i = 0; i < ORDER / 2; i++) {
            newChild->children[i] = splitNode->children[i + ORDER / 2];
            splitNode->children[i + ORDER / 2] = NULL;
        }
    }

    splitNode->numKeys = ORDER / 2 - 1;
    parent->numKeys++;

    for (int i = parent->numKeys; i > index + 1; i--) {
        parent->children[i] = parent->children[i - 1];
    }

    parent->children[index + 1] = newChild;
    parent->keys[index] = splitNode->keys[ORDER / 2 - 1];
}

void insertNonFull(Node *node, int key) {
    int i = node->numKeys - 1;

    if (node->isLeaf) {
        while (i >= 0 && key < node->keys[i]) {
            node->keys[i + 1] = node->keys[i];
            i--;
        }

        node->keys[i + 1] = key;
        node->numKeys++;
    } else {
        while (i >= 0 && key < node->keys[i]) {
            i--;
        }

        i++;

        if (node->children[i]->numKeys == ORDER - 1) {
            splitChild(node, i);

            if (key > node->keys[i]) {
                i++;
            }
        }

        insertNonFull(node->children[i], key);
    }
}

void insert(Node **root, int key) {
    Node *temp = *root;

    if (temp->numKeys == ORDER - 1) {
        Node *newRoot = createNode();
        newRoot->isLeaf = 0;
        newRoot->children[0] = temp;
        *root = newRoot;
        splitChild(newRoot, 0);
        insertNonFull(newRoot, key);
    } else {
        insertNonFull(temp, key);
    }
}

void printInOrder(Node *root) {
    if (root != NULL) {
        int i;
        for (i = 0; i < root->numKeys; i++) {
            printInOrder(root->children[i]);
            printf("%d ", root->keys[i]);
        }
        printInOrder(root->children[i]);
    }
}

int main() {
    Node *root = createNode();
    int keys[] = {3, 7, 1, 5, 10, 6, 8, 12, 2, 11, 4, 9};

    for (int i = 0; i < sizeof(keys) / sizeof(keys[0]); i++) {
        insert(&root, keys[i]);
    }

    printf("In-order traversal of B-tree: ");
    printInOrder(root);

    return 0;
}