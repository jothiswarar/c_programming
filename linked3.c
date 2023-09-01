#include <stdio.h>
#include <stdlib.h>
struct node
{
    int d;
    struct node *n;
};
struct node *head, *tail;
/*void  create(int n){
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

}*/
void display()
{
    struct node *c;
    c = head;
    while (c != NULL)
    {
        printf("%d\t", c->d);
        c = c->n;
    }
    printf("\n");
}
void insertbegin(int i)
{
    struct node *n = malloc(sizeof(struct node));
    n->d = i;
    n->n = NULL;
    if (head == NULL)
    {
        head = n;
        tail = n;
    }
    else
    {
        n->n = head;
        head = n;
    }
}
void insertatend(int i)
{
    struct node *n = malloc(sizeof(struct node));
    n->d = i;
    n->n = NULL;
    if (head == NULL)
    {
        head = n;
        tail = n;
    }
    else
    {
        tail->n = n;
        tail = n;
    }
}
void insert(int i, int s)
{
    struct node *c = head, *a;
    struct node *n = malloc(sizeof(struct node));
    n->d = i;
    n->n = NULL;
    if (head != NULL)
    {
        while (c->d != s)
        {
            c = c->n;
        }
        if(c!=tail){
        a = c->n;
        c->n = n;
        n->n = a;}
        else{
            insertatend(i);
        }
    }
    else
    {
        head = n;
        tail = n;
    }
}
int main()
{
    
    insertbegin(5);
    display();
    insert(15, 5);
    insert(10,5);
    display();
    insertatend(35);
    display();
}