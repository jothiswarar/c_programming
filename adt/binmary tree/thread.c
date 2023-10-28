#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct node{
    int a;
    bool ist;
    struct node *left,*right;
};
struct node * leftmost(struct node *a){
    if(a==NULL){
        return NULL;
    }
    while(a->left!=NULL){
        a=a->left;
    }
    return a;
}
struct node* thread(struct node *a){
    if(a==NULL){
        return NULL;
    }
    if(a->left==NULL&&a->right==NULL){
        return a;
    }
    if(a->left!=NULL){
        struct node *b=thread(a->left);
        b->right=a;
        b->ist=1;
        
    }
    if(a->right==NULL){
        return a;
    }
    return thread(a->right);
    
    
}
void inorder(struct node *a){
    if(a!=NULL){
        a=leftmost(a);
        while(a!=NULL){
            printf("%d\t",a->a);
            if(a->ist){
                a=a->right;
            }
            else{
                a=leftmost(a->right);
            }
        }
    }
}
struct node * insert(int *a, int d, int n)
{
    int i= d+1;
    if(d>=n){
        return NULL;
    }
    struct node *c =malloc(sizeof(struct node ));
    c->a=a[d];
    c->ist=false;
    c->left=insert(a,2*(i)-1,n);
    c->right=insert(a,2*(i) ,n);
    
    return c;
}
void main(int argc,char**argv){
    int *a=malloc(sizeof(int)*(argc-1));
    for(int i=1;i<argc;i++){
        a[i-1]=atoi(argv[i]);
    }
    
    struct node *b=insert(a,0,argc-1);
    thread(b);
    inorder(b);
}