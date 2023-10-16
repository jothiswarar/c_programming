#include <stdio.h>
#include <stdlib.h>
struct node{
    int d;
    struct node *n;
};
struct node *front=NULL,*rear=NULL;
void push(int a){
    struct node *c=malloc(sizeof(struct node));
    c->d=a;
    c->n=NULL;
    if(front ==NULL){
        front =c;
        rear=c;
    }
    else{
        rear->n=c;
        rear=c;

    }
}
int pop(){
    if(front ==NULL){
        printf("\nQueue is Empty");
        return -1;
    }
    struct node *c=front;
    int b=c->d;
    front =front->n;
    free(c);
    return b;
}
void main(){
int n;
    do{
        printf("\nEnter choice\n1.Add\n2.pop\n3.exit\n");
        scanf("%d",&n);
        switch(n){
            case 1:
                {
            int a;
            printf("enter the element:");
            scanf("%d",&a);
            push(a);
            printf("Added sucessfully.\n");
            break;
            }
            case 2:
                {
                    int i=pop();
                    if(i!=-1)
                        printf("first Element:%d\n",i);

                    break;
                }

            default:
                {
                    return 0;
                }
        }
    }while(1);

}
