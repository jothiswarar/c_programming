#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node * insert(int *a, int d, int n)
{
    int i= d+1;
    if(d>=n){
        return NULL;
    }
    struct node *c =malloc(sizeof(struct node ));
    c->data=a[d];
    c->left=insert(a,2*(i)-1,n);
    c->right=insert(a,2*(i) ,n);
    
    return c;
}
void intraverse(struct node *c)
{
    if (c == NULL)
    {
        return;
    }
    else
    {
        intraverse(c->left);
        printf("%d\t", c->data);
        intraverse(c->right);
    }
}
void pretraverse(struct node *c)
{
    if (c == NULL)
    {
        return;
    }
    else
    {
        printf("%d\t", c->data);
        pretraverse(c->left);
        pretraverse(c->right);
    }
}
void posttraverse(struct node *c)
{
    if (c == NULL)
    {
        return;
    }
    else
    {
        posttraverse(c->left);
        posttraverse(c->right);
        printf("%d\t", c->data);
    }
}
void main()
{
    struct node *root = NULL;
    printf("Enter no. of nodes:");
    int n;
    scanf("%d", &n);
    printf("Enter values :");
    int *a = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", a + i);
    }
    root=insert(a, 0  , n);
    printf("Inorder:");
    intraverse(root);
    printf("\nPreorder:");pretraverse(root);
    printf("\npostorder:");posttraverse(root);
}