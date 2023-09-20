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
void display()
{
    node *c;

    if (head == NULL)
    {
        printf("List is Empty\n");
    }
    else
    {
        printf("Enter 1 for printing from start to end and -1 for end to start\n");
        int i;
        scanf("%d", &i);
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

void insert(int a, int s)
{
    struct node *c = head;
    struct node *n = malloc(sizeof(struct node));
    n->data = a;
    n->n = NULL;
    n->p = NULL;
    if (head != NULL)
    {

        for (int i = 1; i < s && c != NULL; i++)
        {
            c = c->n;
        }
        if (c == tail)
        {
            tail->n = n;
            n->p = tail;
            tail = n;
        }
        else if (c == NULL)
        {
            printf("The element is not present in the list");
        }
        else
        {
            struct node *a = c->n;
            a->p = n;
            n->p = c;
            c->n = n;
            n->n = a;
        }
    }
    else
    {
        head = n;
        tail = n;
    }
}
void deleteatbegin()
{
    if (head != NULL)
    {
        struct node *c = head;
        head = head->n;
        head->p = NULL;
        free(c);
    }
    else
    {
        printf("List is already empty\n");
    }
}
void deleteatend()
{
    if (head != NULL)
    {
        struct node *a = tail;
        tail = tail->p;
        free(a);
        tail->n = NULL;
    }
    else
    {
        printf("List is already empty\n");
    }
}
void delete()
{
    int a;

    struct node *c = head;
    if (head != NULL)
    {
        printf("Enter the Position of the element to be deleted:");
        scanf("%d", &a);
        if (a > 0)
        {
            for (int i = 0; i < a; i++)
            {
                c = c->n;
                if (c == NULL)
                {
                    printf("Length out of context\n");
                    return;
                }
            }
            if (c == tail)
            {
                tail = tail->p;
                tail->n = NULL;
                free(c);
            }
            else
            {
                struct node *b = c->n;
                c->p->n = b;
                b->p = c->p;
                free(c);
            }
        }
        else
        {
            head = head->n;
            head->p = NULL;
            free(c);
        }
    }
    else
    {
        printf("List is already empty\n");
    }
}
void search()
{
    struct node *c = head;
    int count;
    int i;
    if (head != NULL)
    {
        printf("Enter the Element to be Searched:");
        scanf("%d", &i);
        count = 1;
        while (c->data != i)
        {
            count++;
            c = c->n;
            if (c == NULL)
            {
                break;
            }
        }
        if (c != NULL)
        {
            printf("%d is found at %d\n", i, count);
        }
        else
        {
            printf("Element not found\n");
        }
    }
    else
    {
        printf("List is Empty\n");
    }
}
void lengthp()
{

    struct node *c = head;
    int l = 0;
    while (c != NULL)
    {
        c = c->n;
        l++;
    }
    if (l != 0)
    {
        printf("length of the list is %d\n", l);
    }
    else
    {
        printf("List  is empty\n");
    }
}
void input(int *c)
{
    printf("Enter 1 for inserting an element at begining\nEnter 2 for inserting an element at the end\n");
    printf("Enter 3 for inserting an element at random position\n");
    printf("Enter 4 for deleting an element at begining\nEnter 5 for Deleting an element at the end\n");
    printf("Enter 6 for deleting an element at random position\n");
    printf("Enter 7 to display the length of the List\n");
    printf("Enter 8 to Search an element\n");
    printf("Enter 9 to Display the list\n");
    scanf("%d", c);
}

int main()
{

    while (1)
    {
        int c;
        input(&c);
        int i;
        switch (c)
        {
        case 1:
        {
            printf("Enter the Element:");
            scanf("%d", &i);
            insertatbegin(i);
            break;
        }
        case 2:
        {
            printf("Enter the Element:");
            scanf("%d", &i);
            insertatend(i);
            break;
        }
        case 3:
        {
            printf("Enter the Element:");
            scanf("%d", &i);
            int a;
            printf("Enter the Position:");
            scanf("%d", &a);
            insert(i, a);
            break;
        }
        case 4:
        {
            deleteatbegin();
            break;
        }
        case 5:
        {
            deleteatend();
            break;
        }
        case 6:
        {
            delete ();
            break;
        }
        case 7:
        {
            lengthp();
            break;
        }
        case 8:
        {
            search();
            break;
        }
        case 9:
        {
            display();
            break;
        }
        default:
        {
            printf("Enter a valid input.\n");
            continue;
        }
        }
        printf("To continue enter 1 and To exit enter 0\n");
        scanf("%d", &c);
        if (c == 0)
        {
            break;
        }
        else
        {
            continue;
        }
    }
}
