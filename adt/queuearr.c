#include <stdio.h>
#include <stdlib.h>
#define capacity 10
int queue[capacity];
int front=0,rear=9, size=0;

int isFull(){
    return size == capacity;
}
int isEmpty(){
    return size==0;
}
void enqueue(int a){
    if(isFull()){
        printf("Queue is Full\n");
    }
    else{
        rear=(rear+1)%capacity;
        queue[rear]=a;
        printf("%d is Enqueued\n",a);
        size++;
    }
}
int dequeue(){
    if(isEmpty()){
        return -1;
    }
    else{
        int a=queue[front];
        size--;
        front=(front+1) % capacity;
        return a;
    }
}
int main(){
    int n;
    scanf("%d",&n);
   
    for(int i=0;i<n;i++){
        int a;
        scanf("%d",&a);
        enqueue(a);
    }
    dequeue();
    dequeue();
    dequeue();
    while(!isFull()){
        int a;
        scanf("%d",&a);
        enqueue(a);
    }
    while(!isEmpty()){
        printf("%d\n",dequeue());
    }
}