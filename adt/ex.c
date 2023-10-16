#include <stdio.h>
#include <stdlib.h>
int stack[100];
int i=-1;
void push(int a){
    if(i==99){
        printf("Stack is full");
    }
    else{
        i++;
        stack[i]=a;
    }
}
int pop(){
    if(i==-1){
        printf("\nStack is Empty");
        return -1;
    }
    else{
        int c=stack[i];
        i--;
        return c;
    }
}
int main(){
    int n;
    do{
        printf("Enter choice\n1.push\n2.pop\n3.exit\n");
        scanf("%d",&n);
        switch(n){
            case 1:
                {
            int a;
            printf("enter the element:");
            scanf("%d",&a);
            push(a);
            printf("pushed sucessfully.\n");
            break;
            }
            case 2:
                {
                    printf("%d\n",pop());
                    break;
                }

            default:
                {
                    return 0;
                }
        }
    }while(1);
}
