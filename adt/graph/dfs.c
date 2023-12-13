#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isStackEmpty(struct stack *s)
{
    return s->top == -1;
}

int isStackFull(struct stack *s)
{
    return s->top == s->size - 1;
}

void push(struct stack *s, int val)
{
    if (isStackFull(s))
    {
        printf("Stack overflow\n");
    }
    else
    {
        s->top++;
        s->arr[s->top] = val;
    }
}

int pop(struct stack *s)
{
    int popped = -1;
    if (isStackEmpty(s))
    {
        printf("Stack underflow\n");
    }
    else
    {
        popped = s->arr[s->top];
        s->top--;
    }
    return popped;
}

int main()
{
    struct stack s;
    s.size = 400;
    s.top = -1;
    s.arr = (int *)malloc(s.size * sizeof(int));

    // DFS Implementation using a stack
    int startNode = 0; // Choose the starting node for DFS
    int visited[7] = {0, 0, 0, 0, 0, 0, 0};
    int adjacencyMatrix[7][7] = {
        {0, 1, 1, 0, 0, 1, 0},
        {0, 0, 0, 1, 0, 0, 0},
        {1, 0, 0, 1, 1, 0, 0},
        {0, 1, 1, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 1},
        {0, 0, 0, 0, 1, 1, 0}};

    printf("%d ", startNode);
    push(&s, startNode);
    visited[startNode] = 1;

    while (!isStackEmpty(&s))
    {
        int currentNode = pop(&s);
        for (int i = 0; i < 7; i++)
        {
            if (adjacencyMatrix[currentNode][i] == 1 && visited[i] == 0)
            {
                printf("%d ", i);
                visited[i] = 1;
                push(&s, i);
            }
        }
    }

    free(s.arr);
    return 0;
}
