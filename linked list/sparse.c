#include <stdio.h>
#include <stdlib.h>
struct node{
    int row;
    int col;
    int val;
    struct node *n;
};
struct node *h=NULL,*t;
void add(int i,int j,int k){
    struct node *c=malloc(sizeof(struct node));
    c->row=i;
    c->col=j;
    c->val=k;
    c->n=NULL;
    if(h==NULL){
        h=c;
        t=c;
    }
    else{
        t->n=c;
        t=c;
    }
}
void main(){
    int m,n;
    printf("Enter no. of Costumers:");
    scanf("%d",&m);
    printf("Enter no. of items:");
    scanf("%d",&n);
    int a;
    //int a[m][n];
    for(int i=0;i<m;i++){
        printf("Costumer No.%d\n",i+1);
        for(int j=0;j<n;j++){
            printf("Item:%d Enter Quantity:",j+1);
            scanf("%d",&a);
            if(a==0){
                continue;
            }
            add(i,j,a);
        }
    }
    while(h!=NULL){
        printf("%d:%d=%d\n",h->row+1,h->col+1,h->val);
        h=h->n;
    }
}