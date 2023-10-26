#include <stdio.h>
#include <stdlib.h>

struct node {
    int a;
    struct node *left;
    struct node *right;
};

struct node *insert (int a, struct node *root) {
    if(root == NULL) {
        struct node *b = malloc(sizeof(struct node));
        b->a = a;
        b->left = NULL;
        b->right = NULL;
        return b;
    }
    else if (a < root->a) {
        root->left = insert (a, root->left);
    }
    else if(a > root->a) {
        root->right = insert (a, root->right);
    }
    else{
        printf("%d is Duplicate\n",root->a);
        return root;
    }
    return root;
}

void inorder(struct node *a) {
    if(a == NULL) {
        return;
    }
    inorder (a->left);
    printf("%d\t", a->a);
    inorder (a->right);
}

int main(int argc, char *argv[]) {
    struct node *root = NULL;
    int i;
    for(i=1;i<argc;i++) {
        root = insert (atoi(argv[i]), root);
    }
    inorder (root);
}