#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *n;
    struct node *p;
};
struct node *head = NULL;
void insert_at_begin(int a)
{
    struct node *b = malloc(sizeof(struct node));
    b->data = a;
    b->n = NULL;
    b->p = NULL;
    if (head == NULL)
    {
        head = b;
        b->n = head;
        head->p = b;
    }
    else
    {
        head->p->n = b;
        b->p = head->p;
        b->n = head;
        head->p = b;
        head = b;
    }
}
void insert_at_end(int a)
{
    struct node *b = malloc(sizeof(struct node));
    b->data = a;
    b->p=NULL;
    b->n = NULL;

    if (head == NULL)
    {
        head = b;
        b->n = head;
        head->p = b;
    }
    else
    {
        head->p->n = b;
        b->p=head->p;
        b->n = head;
        head->p = b;
        // tail = b;
    }
}
void insert(int a)
{
    struct node *b = malloc(sizeof(struct node)), *c = head;
    b->data = a;
    b->n = NULL;
    b->p = NULL;
    if (head == NULL)
    {
        head = b;
        b->n = head;
        head->p = b;
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
        c->n->p = b;
        c->n = b;
        b->p = c;
        if (c == head)
        {
            head = b;
        }
    }
}
void delete_at_end()
{
    struct node *c;
    c = head->p;
    c->p->n = head;
    head->p = c->p;
    free(c);
}
void display()
{
    struct node *c = head;
    if (head!= NULL)
    {
        printf("Forward:");
        do
        {
            printf("%d\t", c->data);
            c = c->n;
        } while (c != head);
        printf("\nReverse:");
        c = head;
        do
        {
            c = c->p;
            printf("%d\t", c->data);
        } while (c != head);
        printf("\n");
    }
    else{
        printf("List is empty\n");
    }
}
void delete_at_begin()
{
    struct node *c = head;
    head->p->n = c->n;
    head->n->p = c->p;
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

        for (int i = 0; i < p; i++)
        {
            c = c->n;
        }

        if (c == head)
        {
            head->p->n = head->n;
            head->n->p = head->p;
            head = c->n;
            free(c);
        }
        else
        {
            c->p->n = c->n;
            c->n->p = c->p;
            free(c);
        }
    }
}
void search()
{
    struct node *c = head;
    if (head == NULL)
    {
        printf("The list is Empty\n");
        return;
    }
    printf("Enter the element:");
    int a, i = 1;
    scanf("%d", &a);
    while (c->n != head && c->data != a)
    {
        c = c->n;
        i++;
    }
    if (c->data == a)
    {
        printf("The Element %d is found at %d\n", a, i);
    }
    else
    {
        printf("The Element %d is not Found.\n", a);
    }
}
void main()
{
    // delete();
    display();
    insert(20);
    insert_at_end(50);
    insert_at_begin(10);
    display();
    insert(30);
    insert(40);
    display();
    delete_at_begin();
    display();
    delete_at_end();
    display();
    delete ();
    display();
    search();
}
