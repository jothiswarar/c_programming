#include <stdio.h>
#include <stdlib.h>
#define capacity 10
int queue[capacity];
int front = -1, rear = -1;
int isFull()
{
    return (rear + 1) % capacity == front;
}
int isEmpty()
{
    return front == -1 && rear == -1;
}
void enqueue(int a)
{
    if (isFull())
    {
        printf("Queue is Full\n");
    }
    else
    {
        if (isEmpty())
        {
            front = 0;
        }
        rear = (rear + 1) % capacity;
        queue[rear] = a;
        printf("%d is Enqueued\n", a);
    }
}
int dequeue()
{
    if (isEmpty())
    {
        printf("QUEUE is Empty\n");
        return -1;
    }
    else
    {
        int a = queue[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % capacity;
        }
        //printf("%d is deueues\n", a);

        return a;
    }
}
int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int a;
        scanf("%d", &a);
        enqueue(a);
    }
    dequeue();
    dequeue();
    dequeue();
    while (!isFull())
    {
        int a;
        scanf("%d", &a);
        enqueue(a);
    }
    while (!isEmpty())
    {
        printf("%d\n", dequeue());
    }
}