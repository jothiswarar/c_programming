#include <stdio.h>
#include <stdlib.h>
typedef struct PCB
{
    int pid;
    int priority;
    int waitingtime;
    int bursttime;
    struct PCB *next;
    struct PCB *prev;
}pcb;
struct PCB *tail = NULL, *head = NULL;
int wait = 0;
float avg = 0.0;
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
pcb* priority(){
    if(head==NULL){
        return NULL;
    }
    pcb *a=head,*b=head;
    while(a!=NULL){
        if(a->priority<b->priority){
            b=a;
        }
        a=a->next;
    }
    return b;
}
void run()
{
    struct PCB *a = priority();
    while (a != NULL)
    {
        a->waitingtime = wait + a->bursttime;
        wait = wait + a->bursttime;
        printf("\nPID:%d", a->pid);
        printf("\nCPU Burst Time:%d", a->bursttime);
        printf("\nWaiting Time:%d\n", a->waitingtime);
        avg+=(float)a->waitingtime;
        
        if(a==head && tail==a){
            head=tail=NULL;
            
        }
        else if(a==head){
            a->next->prev=NULL;
            head=a->next;
           
        }
        else if(a==tail){
            tail->prev->next=NULL;
            tail=tail->prev;
        }
        else{
            pcb *b,*c;
            b=a->prev;
            c=a->next;
            b->next=c;
            c->prev=b;
            
        }
        free(a);
        a = priority();
        //printf("i");
    }
    
}
void input(struct PCB *a)
{
    printf("\nEnter the Burst Time:");
    scanf("%d", &a->bursttime);
    printf("Enter the Priority:");
    scanf("%d", &a->priority);
}
int main()
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
    run();
    avg=avg/(float)n;
    printf("Average Waiting Time:%f",avg);
}