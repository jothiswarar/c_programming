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
struct node *stack[100];
int top=-1;
void push(struct node *a){
    if(top!=99){
        stack[++top]=a;
    }
}
struct node *pop(){
    if(top!=-1){
        return stack[top--];
    }
    return NULL;
}
void inorder(struct node *c){
    do{
        if(c->left!=NULL){
            push(c);
            c=c->left;
        }
        else{
            printf("%d\t",c->data);
            if(c->right!=NULL){
                c=c->right;
                
            }
            else{
                c=pop();
                if(c==NULL){
                    break;
                }
                printf("%d\t",c->data);
                c=c->right;
            }
        }
    }while(top!=-1||c!=NULL);
}
void preorder(struct node *c){
    do{
        printf("%d\t",c->data);
        if(c->left!=NULL){
            
            push(c);
            c=c->left;
        }
        else{
            
            if(c->right!=NULL){
                c=c->right;
                
            }
            else{
               
                c=pop();
                
                
                c=c->right;
            }
        }
    }while(top!=-1||c!=NULL);
}
void postorder(struct node *c){
    do{
        if(c->left!=NULL){
            
            push(c);
            c=c->left;
        }
        else{
            
            if(c->right!=NULL){
                
                c=c->right;
                
            }
            else{
                printf("%d\t",c->data);
                if(c==stack[top]->right){
                    printf("%d\t",stack[top]->data);
                    
                }
                c=pop();
                if(c==NULL){
                    break;
                }
                
                c=c->right;
            }
        }
    }while(top!=-1||c!=NULL);
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
    int n=6;
    scanf("%d", &n);
    printf("Enter values :");
    int *a = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        
        scanf("%d", a + i);
    }
    root=insert(a, 0  , n);
    printf("Inorder:");
    inorder(root);
    printf("\nPreorder:");preorder(root);
    printf("\npostorder:");postorder(root);
}