#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node*n;
};
struct node *top=NULL;
void push(int b){
    struct node *a=malloc(sizeof(struct node));
    a->data=b;
    a->n=NULL;
    if(top!=NULL){
        a->n=top;
    }
    top=a;

}
int pop(){
    if(top==NULL){
        printf("\nStack is empty ");
        return -1;
    }
    int b=top->data;
    struct node *c=top;
    top=top->n;
    free(c);
    return b;

}
