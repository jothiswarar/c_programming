#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *n;
};
struct node *head = NULL, *tail = NULL;
void insert_at_begin(int a)
{
    struct node *b = malloc(sizeof(struct node));
    b->data = a;
    b->n = NULL;
    if (head == NULL)
    {
        head = b;
        b->n = head;
        tail = b;
    }
    else
    {
        tail->n = b;
        b->n = head;
        head = b;
    }
}
void insert_at_end(int a)
{
    struct node *b = malloc(sizeof(struct node));
    b->data = a;
    b->n = NULL;
    if (head == NULL)
    {
        head = b;
        b->n = head;
        tail = b;
    }
    else
    {
        tail->n = b;
        b->n = head;
        tail = b;
    }
}
void insert(int a)
{
    struct node *b = malloc(sizeof(struct node)), *c = head;
    b->data = a;
    b->n = NULL;
    if (head == NULL)
    {
        head = b;
        b->n = head;
        tail = b;
    }
    else
    {
        printf("Enter position:");
        int p;
        scanf("%d", &p);
        for (int i = 0; i < p - 1; i++)
        {
            c = c->n;
        }
        b->n = c->n;
        c->n = b;
        if (c == tail)
        {
            tail = b;
        }
        else if (c == head)
        {
            tail = head;
           head = b;
        }
    }
}
void delete_at_end()
{
    struct node *c = head, *a = tail;
    while (c->n != tail)
    {
        c = c->n;
    }
    c->n = head;
    tail = c;
    free(a);
}
void display()
{
    struct node *c = head;
    do
    {
        printf("%d\t", c->data);
        c = c->n;
    } while (c != head);
    printf("\n");
}
void delete_at_begin()
{
    struct node *c = head;
    tail->n = c->n;
    head = c->n;
    free(c);
}
void delete()
{
    if (head == NULL)
    {
        printf("List is Empty\n");
        return;
    }
    struct node *c = head;
    if (head->n == head)
    {

        head = NULL;
        c->n = NULL;
        free(c);
    }
    else
    {
        printf("Enter the position:");
        int p;
        scanf("%d", &p);
        if (p > 0)
        {
            for (int i = 0; i < p - 1; i++)
            {
                c = c->n;
            }
            if (c->n == tail)
            {
                struct node *a=c->n;
                c->n = head;
                tail = c;
                free(a);
            }
            else if (c == tail)
            {
                struct node *a=c->n;
                tail->n = head->n;
                head = c->n;
                free(a);
            }
            else
            {
                struct node *b = c->n;
                c->n = b->n;
                free(b);
            }
        }
        else
        {
            tail->n = c->n;
            head = c->n;
            free(c);
        }
    }
}
void search(){
    struct node *c=head;
    if(head==NULL){
        printf("The list is Empty\n");
        return;
    }
    printf("Enter the element:");
    int a,i=1;
    scanf("%d",&a);
    while(c->n!=head&&c->data!=a){
        c=c->n;
        i++;
    }
    if(c->data==a){
        printf("The Element %d is found at %d\n",a,i);
    }
    else{
        printf("The Element %d is not Found.\n",a);
    }
}
void main()
{
    //delete();
    insert(10);
    insert_at_end(50);
    insert_at_begin(0);
    display();
    insert(20);
    insert(60);
    display();
    delete_at_begin();
    display();
    delete_at_end();
    display();
    delete();
    display();
    search();

}
