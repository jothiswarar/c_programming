#include <stdio.h>
#include <stdlib.h>
struct PCB
{
    int pid;
    int priority;
    int waitingtime;
    int bursttime;
    struct PCB *next;
    struct PCB *prev;
};
struct PCB *tail = NULL, *head = NULL;
int wait = 0;
void add(struct PCB *a)
{
    if (head == NULL)
    {
        head = tail = a;
        a->prev = NULL;
    }
    else
    {
        tail->next = a;
        a->prev = tail;
        tail = a;
    }
    a->next = NULL;
}
void swap(struct PCB *a, struct PCB *b)
{
    if (a == head)
    {
        head = b;
    }
    if (a->prev != NULL)
    {
        a->prev->next = b;
    }
    if (b->next != NULL)
    {
        b->next->prev = a;
    }
    struct PCB *t = b->next;
    b->next = a->next;
    a->next = t;
    t = b->prev;
    b->prev = a->prev;
    a->prev = t;
}
void sort()
{
    struct PCB *c;
    int i;
    do
    {
        i = 0;
        c = head;
        while (c->next != NULL)
        {
            if (c->priority > c->next->priority)
            {
                swap(c, c->next);
                i = 1;
            }
            c = c->next;
        }
    } while (i);
}
void run()
{
    struct PCB *a = head;
    while (a != NULL)
    {
        a->waitingtime = wait + a->bursttime;
        wait = wait + a->bursttime;
        printf("\nPID:%d", a->pid);
        printf("\nCPU Burst Time:%d", a->bursttime);
        printf("\nWaiting Time:%d\n", a->waitingtime);
        a = a->next;
    }
}
void input(struct PCB *a)
{
    printf("\nEnter the Burst Time:");
    scanf("%d", &a->bursttime);
    printf("Enter the Priority:");
    scanf("%d", &a->priority);
}
void main()
{
    int n;
    printf("Enter no. of processes:");
    scanf("%d", &n);
    struct PCB *temp;
    for (int i = 0; i < n; i++)
    {
        temp = malloc(sizeof(struct PCB));
        input(temp);
        temp->pid=i;
        temp->waitingtime = 0;
        add(temp);
    }
    sort();
    run();
    temp = head;
    float avg = 0.0;
    while (temp != NULL)
    {
        avg += temp->waitingtime;
        temp = temp->next;
    }
    avg=avg/n;
    printf("Average Waiting Time:%d",avg);
}