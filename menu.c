#include <stdio.h>
#include <stdlib.h>
struct node
{
    int d;
    struct node *n;
};
struct node *head, *tail;

void display()
{
    struct node *c;
    c = head;
    if (c == NULL)
    {
        printf("List is Empty\n");
    }
    else
    {
        while (c != NULL)
        {
            printf("%d\t", c->d);
            c = c->n;
        }

        printf("\n");
    }
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
        if (s == 1)
        {
            insertbegin(i);
        }
        else
        {
            for (int i = 1; i < s; i++)
            {
                c = c->n;
            }
            struct node *a = c->n;
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
    struct node *c = head;
    head = head->n;
    free(c);
}
void deleteatend()
{
    struct node *c = head;
    while (c->n != tail)
    {
        c = c->n;
    }
    tail = c;

    struct node *a = c->n;
    free(a);
    c->n = NULL;
}
void delete(int a)
{
    struct node *c = head;
    while (c->n->d != a)
    {
        c = c->n;
    }
    struct node *b = c->n;
    c->n = b->n;
    free(b);
}
void search(int i)
{
    struct node *c = head;
    int count;
    if (head != NULL)
    {
        count = 1;
        while (c->d != i)
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
void length()
{
    struct node *c = head;
    int l = 0;
    while (c != NULL)
    {
        l++;
        c = c->n;
    }
    printf("Length of the List is %d\n", l);
}

void check(int c)
{
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
    int c;
    input(&c);
    int i;
    switch (c)
    {
    case 1:
    {

        printf("Enter the Element:");
        scanf("%d", &i);
        insertbegin(i);
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
        printf("Enter the Element to be Deleted:");
        scanf("%d", &i);
        delete (i);
        break;
    }
    case 7:
    {
        length();
        break;
    }
    case 8:
    {
        printf("Enter the Element to be Searched:");
        scanf("%d", &i);
        search(i);
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
        main();
        return 0;
    }
    }
    printf("To continue enter 1 and To exit enter 0");
    scanf("%d", &c);
    if (c != 0)
    {
        main();
    }
    else
    {
        return 0;
    }
}