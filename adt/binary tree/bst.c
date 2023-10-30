#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int a;
    struct node *left;
    struct node *right;
};
struct node *root1 = NULL;
struct node *leftmost(struct node *a)
{
    while (a->left != NULL)
    {
        a = a->left;
    }
    return a;
}
struct node *insert(int a, struct node *root)
{
    if (root == NULL)
    {
        struct node *b = malloc(sizeof(struct node));
        b->a = a;
        b->left = NULL;
        b->right = NULL;
        return b;
    }
    else if (a < root->a)
    {
        root->left = insert(a, root->left);
    }
    else if (a > root->a)
    {
        root->right = insert(a, root->right);
    }
    else
    {
        printf("%d is Duplicate\n", root->a);
        return root;
    }
    return root;
}

void inorder(struct node *a)
{
    if (a == NULL)
    {
        return;
    }
    inorder(a->left);
    printf("%d\t", a->a);
    inorder(a->right);
}
struct node *delete(int a, struct node *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    else if (a < root->a)
    {
        root->left = delete (a, root->left);
    }
    else if (a > root->a)
    {
        root->right = delete (a, root->right);
    }
    else
    {
        printf("\nDeleted");
        if (root->left != NULL && root != NULL)
        {
            struct node *b = leftmost(root->right);
            root->a = b->a;
            root->right = delete (b->a, root->right);
        }
        else
        {

            if (root->left != NULL)
            {

                return root->left;
            }
            else
            {

                return root->right;
            }
        }
    }
    return root;
}
bool deletesinglenode(struct node **a)
{
    if ((*a) == NULL)
    {
        return false;
    }
    else
    {
        if ((*a)->left != NULL && (*a)->right == NULL)
        {
            struct node *c = (*a);
            (*a) = (*a)->left;
            free(c);
            return true;
        }
        else if ((*a)->right != NULL && (*a)->left == NULL)
        {
            struct node *c = (*a);
            (*a) = (*a)->right;
            free(c);
            return true;
        }
        else
        {
            if ((*a)->left == NULL)
            {
                return false;
            }
            else
            {
                if (deletesinglenode(&(*a)->left))
                {
                    return true;
                }
                else if (deletesinglenode(&(*a)->right))
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
        }
    }
}
bool deletedouble(struct node **a)
{
    if (*a == NULL)
    {
        return false;
    }
    else if ((*a)->left != NULL && (*a)->right != NULL)
    {
        struct node *b = leftmost((*a)->right);
        (*a)->a = b->a;
        (*a)->right = delete (b->a, (*a)->right);
        return true;
    }
    else
    {
        if (deletedouble(&(*a)->left))
        {
            return true;
        }
        else if (deletedouble(&(*a)->right))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
int search(int b, int i, struct node *a)
{
    if (a == NULL)
    {
        return -1;
    }
    else if (a->a == b)
    {
        return i;
    }
    else if (a->a > b)
    {
        return search(b, (2 * i) + 1, a->left);
    }
    else
    {
        return search(b, (2 * i) + 2, a->right);
    }
}
int main(int argc, char **argv)
{

    int i;

    for (i = 1; i < argc; i++)
    {
        root1 = insert(atoi(argv[i]), root1);
    }

    do
    {
        int i;
        printf("\nEnter Choice:\n1.Inserting a Element\n2.Deleting a node\n3.Search an Element\n4.Display\n0.Exit\n");
        scanf("%d", &i);
        switch (i)
        {
        case 1:
            printf("Enter the element to be inserted\n");
            int a;
            scanf("%d", &a);
            root1 = insert(a, root1);
            break;
        case 2:
        {
            if (root1 == NULL)
            {
                printf("Tree is Empty\n");
                break;
            }
            int a;
            printf("Enter 1.Deleting a node(value)\n2.Deleting singlechild node\n3.Deleting Double child node\n");
            scanf("%d", &a);
            switch (a)
            {
            case 1:
                printf("Enter the value to be deleted\n");
                int b;
                scanf("%d", &b);
                root1 = delete (b, root1);
                break;
            case 2:

                if (deletesinglenode(&root1))
                {
                    printf("Deleted\n");
                }
                else
                {
                    printf("Not Deleted\n");
                }
                break;
            case 3:
                if (deletedouble(&root1))
                {
                    break;
                }
                else
                {
                    printf("Not Deleted\n");
                    break;
                }

            default:
                printf("Wrong Choice\n");
                break;
            }

            break;
        }
        case 4:
            if (root1 == NULL)
            {
                printf("Tree is Empty\n");
                break;
            }
            inorder(root1);
            break;
        case 0:
            return 0;
        case 3:
        {
            if (root1 == NULL)
            {
                printf("Empty\n");
                break;
            }
            int a;
            printf("Enter the Element to be searched:");
            scanf("%d", &a);
            a = search(a, 0, root1);
            if (a == -1)
            {
                printf("Not Found\n");
            }
            else
            {
                printf("Found at position %d\n", a);
            }
            break;
        }
        default:
            printf("Invalid Choice\n");
            break;
        }
    } while (true);
}