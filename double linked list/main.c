#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *p;
    struct node *n;
} node;
node *head = NULL;
node *tail = NULL;
void insertatbegin(int i)
{
    node *c = malloc(sizeof(node));
    c->data = i;
    c->n = NULL;
    c->p = NULL;
    if (head == NULL)
    {
        head = c;
        tail = c;
    }
    else
    {
        c->n = head;
        head->p = c;
        head = c;
    }
}
void insertatend(int i)
{
    struct node *n = malloc(sizeof(struct node));
    n->data = i;
    n->n = NULL;
    n->p = NULL;
    if (head == NULL)
    {
        head = n;
        tail = n;
    }
    else
    {
        tail->n = n;
        n->p = tail;
        tail = n;
    }
}
void display(int i)
{
    node *c;

    if (head == NULL)
    {
        printf("List is Empty\n");
    }
    else
    {
        if (i > 0)
        {
            c = head;
            while (c != NULL)
            {
                printf("%d\t", c->data);
                c = c->n;
            }
        }
        else
        {
            c = tail;
            while (c != NULL)
            {
                printf("%d\t", c->data);
                c = c->p;
            }
        }

        printf("\n");
    }
}

void insert(int i, int s)
{
    struct node *c = head;
    struct node *n = malloc(sizeof(struct node));
    n->data = i;
    n->n = NULL;
    n->p = NULL;
    if (head != NULL)
    {

        for (int i = 1; i < s; i++)
        {
            c = c->n;
        }
        struct node *a = c->n;
        a->p = n;
        n->p = c;
        c->n = n;
        n->n = a;
    }
    else
    {
        head = n;
        tail = n;
    }
}
int main()
{

    insertatbegin(5);
    insert(15,1);
    insertatend(35);
    display(1);
    display(-1);
}
