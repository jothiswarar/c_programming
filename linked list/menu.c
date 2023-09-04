#include <stdio.h>
#include <stdlib.h>
struct node
{
    int d;
    struct node *n;
};
struct node *head=NULL, *tail=NULL;

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
