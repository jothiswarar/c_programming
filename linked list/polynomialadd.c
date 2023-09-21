#include <stdio.h>
#include <stdlib.h>
struct node{
    int pow;
    int val;
    struct node *n;
};
struct node * poly(){
    int n;
    printf("Enter no. of values:");
    scanf("%d",&n);
    struct node *a=NULL;
    for(int i=0;i<n;i++){
        struct node *b=malloc(sizeof(struct node));
        printf("Enter power:");
        scanf("%d",&(b->pow));
        printf("Enter coefficient:");
        scanf("%d",&(b->val));
        b->n=a;
        a=b;
    }
    return a;

}
void swap(struct node *a,struct node *b){
    struct node *c=malloc(sizeof(struct node));
    c->pow=a->pow;
    c->val=a->val;
    a->pow=b->pow;
    a->val=b->val;
    b->pow=c->pow;
    b->val=c->val;
    
}
struct node * sort(struct node *a){
    struct node *c=a;
    for(;a!=NULL;a=a->n){
        struct node *b=a;
    while(b!=NULL&&b->n!=NULL){
            if(b->pow<b->n->pow){
                swap(b,b->n);
            }
            else if(b->pow==b->n->pow){
                b->val+=b->n->val;
                struct node *k=b->n;
                b->n=k->n;
                free(k);
            }
            b=b->n;
        }
    }
    return c;

}

struct node *add(struct node *a,struct node *b){
    struct node*c;
    
    if(a==NULL&&b==NULL){
        return NULL;
    }
    else if((a!=NULL&&b!=NULL)&&a->pow==b->pow){
        c=malloc(sizeof(struct node));
        c->pow=a->pow;
        c->val=a->val+b->val;
        c->n=add(a->n,b->n);

    }
    else if(a==NULL||a->pow<b->pow){
        c=malloc(sizeof(struct node));
        c->pow=b->pow;
        c->val=b->val;
        c->n=add(a,b->n);
    }
    else {
        c=malloc(sizeof(struct node));
        c->pow=a->pow;
        c->val=a->val;
        c->n=add(a->n,b);
    }
    return c;
}

void main(){
    struct node *a=poly(),*b=poly();
    
    struct node *c=add(sort(a),sort(b));
    while(1){
        printf("%dx^%d",c->val,c->pow);
        c=c->n;
        if(c==NULL){
            break;
        }
        printf("+");
    }

}
