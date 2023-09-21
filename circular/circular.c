#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *n;
};
struct node *head=NULL,*tail=NULL;
void insert_at_begin(int a){
    struct node *b=malloc(sizeof(struct node));
    b->data=a;
    b->n=NULL;
    if(head==NULL){
        head=b;
        b->n=head;
        tail=b;
    }
    else{
        tail->n=b;
        b->n=head;
        head=b;
    }
}
void insert_at_end(int a){
    struct node *b=malloc(sizeof(struct node));
    b->data=a;
    b->n=NULL;
    if(head==NULL){
        head=b;
        b->n=head;
        tail=b;
    }
    else{
        tail->n=b;
        b->n=head;
        tail=b;
    }
}
void insert(int a){
    struct node *b=malloc(sizeof(struct node)),*c=head;
    b->data=a;
    b->n=NULL;
    if(head==NULL){
        head=b;
        b->n=head;
        tail=b;
    }
    else{
        printf("Enter position:");
        int p;
        scanf("%d",&p);
        for(int i=0;i<p-1;i++){
            c=c->n;
        }
        b->n=c->n;
        c->n=b;
        if(c==tail){
            tail=b;
        }
        else if(c==head){
            tail=head;
            head=b;
            
        }
    }
}
void delete_at_end(){
    struct node *c=head,*a=tail;
    while(c->n!=tail){
        c=c->n;
    }
    c->n=head;
    tail=c;
    free(a);
}
void dispaly(){
    struct node *c=head;
    do
    {
        printf("%d\t",c->data);
        c=c->n;
    }while(c!=head);
    printf("\n");
    
}
void delete_at_begin(){
    struct node *c=head;
    tail->n=c->n;
    head=c->n;
    free(c);
}
void main(){
    insert_at_begin(10);
    insert_at_begin(20);
    insert_at_end(30);
    insert(40);
    dispaly();
    delete_at_end();
    dispaly();
}
