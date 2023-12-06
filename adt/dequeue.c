#include <stdio.h>
#define s 10
int queue[s];
int f = -1, r = -1;
void insertf(int x)
{
    if (f == (r + 1) % s)
    {
        printf("Queue is Full");
    }
    else if (f == -1 && r == -1)
    {
        f = r = 0;
        queue[f] = x;
    }
    else if (f == 0)
    {
        f = s - 1;
        queue[f] = x;
    }
    else
    {
        queue[--f] = x;
    }
}
void insertr(int x)
{
    if (f == (r + 1) % s)
    {
        printf("Queue is Full");
    }
    else if (f == -1 && r == -1)
    {
        f = r = 0;
        queue[f] = x;
    }
    else if (r == s - 1)
    {
        r = 0;
        queue[r] = x;
    }
    else
    {
        queue[++r] = x;
    }
}
void dis()
{
    int i = f;
    printf("elements are ");
    while (i != r)
    {
        printf("%d\t", queue[i]);
        i++;
        i %= s;
    }
    printf("%d\n", queue[i]);
}
void deletef()
{
    if (f == -1 && r == -1)
    {
        printf("queue is empty\n");
    }
    else if (f == r)
    {
        printf("%d is deleted\n", queue[f]);
        f = -1;
        r = -1;
    }
    else
    {
        printf("%d is deleted\n", queue[f]);
        f++;
        f %= s;
    }
}
void deleter()
{
    if (f == -1 && r == -1)
    {
        printf("queu is empty\n");
    }
    else if (f == r)
    {
        printf("%d is deleted\n", queue[f]);
        f = -1;
        r = -1;
    }
    else if (r == 0)
    {
        printf("%d is deleted\n", queue[r]);
        r = s - 1;
    }
    else
    {
        printf("%d is deleted\n", queue[r]);
        r--;
    }
}
void main()
{
   insertr(6);insertr(9);
    insertf(1);
    insertr(2);
    insertf(4);
    insertf(5);
    insertr(6);insertr(9);
    dis();
    deletef();
    deleter();
    deleter();
    deletef();
    dis();

}