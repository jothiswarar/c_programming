#include <stdio.h>
#include <stdlib.h>

struct node{
    int d;
    struct node *n;

};
struct node *head,*tail;
void  create(int n){
    struct node *new=(struct node *)malloc(sizeof(struct node));
    new->d=n;
    new->n=NULL;
    if(head==NULL){
        head=new;
        tail=new;
    }
    else{
        tail->n=new;
        tail=new;
    }
     
}
void display(){
    struct node *c;
    c=head;
    while(c!=NULL){
        printf("%d\t",c->d);
        c=c->n;
    }
    printf("\n");
}
void insertbegin(int i){
    struct node *n=malloc(sizeof(struct node));
    n->d=i;
    n->n=head;
    head=n;

}
void insertatend(int i){
    struct node *n=malloc(sizeof(struct node));
    n->d=i;
    n->n=NULL;
    tail->n=n;
    tail=n;
}
void insert(int i,int s){
    struct node *c=head,*a;
    struct node*n=malloc(sizeof(struct node));
    n->d=i;
    n->n=NULL;
    while(c->d!=s){
        c=c->n;
    }
    a=c->n;
    c->n=n;
    n->n=a;

}
void deleteatbegin(){
    struct node *c=head;
    head=head->n;
    free(c);
}
void deleteatend(){
    struct node *c=head;
    while(c->n!=tail){
        c=c->n;

    }
    tail=c;
    
    struct node *a=c->n;
    free(a);
    c->n=NULL;
}
void delete(int a){
    struct node *c=head;
    while(c->n->d!=a){
        c=c->n;
    }
    struct node *b= c->n;
    c->n=b->n;
    free(b);
}
int main(){
    create(10);
    create(20);
    create(30);
    display();
    insertbegin(5);
    insert(15,10);
    insertatend(35);
    display();
    deleteatbegin();
    deleteatend();
    delete(15);
    display();
}