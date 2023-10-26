#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
struct node
{
    int data;
    char n;
    bool isn;
    struct node *left;
    struct node *right;
};
struct stack
{
    struct node *a;
    struct stack *b;
};

struct stack *top = NULL;
bool check(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

void push(struct node *a)
{
    struct stack *b = malloc(sizeof(struct stack));
    b->a = a;
    if (top != NULL)
    {
        b->b = top;
    }
    top = b;
}
struct node *pop()
{
    struct stack *b = top;
    struct node *c = b->a;
    if (top == NULL)
    {
        return NULL;
    }
    top = top->b;
    free(b);
    return (c);
}
int evaluate(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else if (root->isn)
    {
        int a = evaluate(root->left);
        int b = evaluate(root->right);
        

        switch (root->n)
        {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
        {

            return a * b;
        }
        case '/':
            if (b != 0)
            {
                return a / b;
            }
            else
            {
                return 0;
            }
        }
    }
    else
    {
        return root->data;
    }
}

struct node *insert(int c, char b)
{
    struct node *a = malloc(sizeof(struct node));
    a->data = c;
    a->n = b;
    a->isn = check(a->n);
    a->right = NULL;
    a->left = NULL;
    if (a->isn)
    {
        a->right = pop();
        a->left = pop();
    }

    push(a);

    return a;
}

/*int main(int argv, char **args)
{
    int n = argv;
    struct node *root;
    for (int i = 1; i < n; i++)
    {
        if (check(args[i][0]))
        {
            root = insert(0, args[i][0]);
        }
        else
        {
            root = insert(atoi(args[i]), '#');
        }
    }

    printf("%d", evaluate(root));
    return 0;
}*/
void inorder(struct node *a)
{
    if (a == NULL)
    {
        return;
    }
    else
    {
        inorder(a->left);
        if (!(a->isn))
        {
            printf("%d ", a->data);
        }
        else
        {
            printf("%c ", a->n);
        }
        inorder(a->right);
    }
}
int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    char input[100]; // Assuming a maximum of 100 characters per input
    printf("Enter the elements: ");

    struct node *root = NULL;

    for (int i = 0; i < n; i++)
    {
        scanf("%s", input);

        if (check(input[0]))
        {
            root = insert(0, input[0]);
        }
        else
        {
            root = insert(atoi(input), '#');
        }
    }
    inorder(root);
    printf("\nResult: %d\n", evaluate(root));
    return 0;
}
