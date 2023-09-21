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
    printf("Enter row and columns:");
    scanf("%d%d",&m,&n);
    int a[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&a[i][j]);
            if(a[i][j]==0){
                continue;
            }
            add(i,j,a[i][j]);
        }
    }
    while(h!=NULL){
        printf("Value at %d:%d=%d\n",h->row,h->col,h->val);
        h=h->n;
    }
}