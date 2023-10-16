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

