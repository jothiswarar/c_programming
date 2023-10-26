#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct node {
    int a;
    struct node *left;
    struct node *right;
};
struct node *root1 = NULL;
struct node *leftmost(struct node *a){
    while(a->left!=NULL){
        a=a->left;
    }
    return a;
}
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
struct node * delete(int a,struct node *root){
    if(root==NULL){
        return NULL;
        
    }
    else if(a<root->a){
        root->left=delete(a,root->left);
    }
    else if(a> root->a){
        root->right=delete(a,root->right);
    }
    else{
        if(root->left!=NULL&&root!=NULL){
            struct node *b=leftmost(root->right);
            root->a=b->a;
            root->right=delete(b->a,root->right);

        }
        else{

            if(root->left!=NULL){
                return root->left;
            }
            else{
                return root->right;
            }
        }
    }
    return root;

}
bool deletesinglenode(struct node **a){
    if((*a)==NULL){
        return (1!=1);
    }
    else{
        if((*a)->left!=NULL&&(*a)->right==NULL){
            struct node *c=(*a);
            (*a)=(*a)->left;
            free(c);
            return (1==1);
        }
        else if((*a)->right!=NULL&&(*a)->left==NULL){
            struct node *c=(*a);
            (*a)=(*a)->right;
            free(c);
            return (1==1);
        }
        else{
            if((*a)->left==NULL){
                return (1!=1);
            }
            else{
                if(deletesinglenode(&(*a)->left)){
                    return (1==1);
                }
                else if (deletesinglenode(&(*a)->right)){
                    return (1==1);
                }
                else{
                    return (1!=1);
                }


            }
        }
    }
}
int main() {
    
    int i;
    int a[]={10,11,13,2,3,12,14};
    for(i=0;i<7;i++) {
        root1 = insert (a[i], root1);
    }
    inorder (root1);
    //root1=delete(2,root1);
    deletesinglenode(&root1);
    deletesinglenode(&root1);
    deletesinglenode(&root1);
    deletesinglenode(&root1);

    
    printf("\n"); 
    inorder(root1);
}