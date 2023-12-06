#include <stdio.h>
struct node{
    int data,ht;
    struct node *left;
    struct node *right;
};
int height(struct  node *a){
    return (a==NULL) ? 1 : a->ht ;
}