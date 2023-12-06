#include <stdio.h>
#include <stdlib.h>
#define s 25
struct node{
    int data,p;
};
struct node *queue[s];
int r = -1;
void heapify(struct node **a, int i, int n)
{

    int l = (2 * i) + 1;
    int r = (2 * i) + 2;
    if (i >= n)
    {
        return;
    }
    int small = i;
    if (l < n && a[small]->p > a[l]->p)
    {
        small = l;
    }
    if (r < n && a[small]->p > a[r]->p)
    {
        small = r;
    }
    if (small != i)
    {
        struct node* b = a[i];
        a[i] = a[small];
        a[small] = b;
        heapify(a, small, n);
    }
}
void enqueue(int x,int p)
{
    struct node *a=malloc(sizeof(struct node));
    a->data=x;
    a->p=p;
    if (r == -1)
    {
        queue[++r]=a;
    }
    else
    {
        queue[++r] = a;
        for (int i = (r) / 2; i >= 0; i--)
        {
            heapify(queue, i, r + 1);
        }
    }
}
int  dequeue()
{
    int a = queue[0]->data;
    struct node *t=queue[0];
    queue[0] = queue[r--];
    free(t);
    for (int i = (r) / 2+1; i >= 0; i--)
    {
        heapify(queue, i, r + 1);
    }
    return a;
}
void delete(int i)
{
    int a;
    int j=0;
    while(i!=queue[j]->data){
        j++;
        if(j>r){
            printf("element not found\n");
            return;
        }
    }
    struct node *t=queue[j];
    queue[j]=queue[r--];
    free(t);
    queue[r+1]=NULL;
    
    for (int i = (r) / 2; i >= 0; i--)
    {
        heapify(queue, i, r + 1);
    }
}
void print(){
    int j=0;
    while(j<=r){
        printf("%d\t%d\n",queue[j]->data,queue[j]->p);
        j++;
    }
}
void main(){
    enqueue(1,2);
    enqueue(2,3);
    enqueue(3,4);
    enqueue(4,1);
    enqueue(5,1);
    enqueue(6,5);
    enqueue(7,7);
    print();
    delete(7);
    while(r>=0){
        int a= dequeue();
        printf("%d is dequeued\n",a);
        
    }
}