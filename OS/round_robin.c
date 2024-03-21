#include <stdio.h>
#include <stdlib.h>
#define time 5
struct PCB{
  int pid;
  int CPUBursttime;
  int waitingTime;
  struct PCB * next;
};
int wait=0;int tl=0;int tw=0;
struct PCB * head=NULL,*tail=NULL;
void add(struct PCB * a){
  if(head==NULL){
    head=a;tail=a;
  }
  else{
    tail->next=a;
    a->next=NULL;
    tail=a;
  }
}
void print(struct PCB * a,int run){
  printf("PID:%d\n",a->pid);
  printf("Remaining CPUBursttime:%d\n",a->CPUBursttime);
  printf("Run:%d\n",run);
  printf("WaitingTime:%d\n\n",a->waitingTime);
}
void run(){
  int t=head->CPUBursttime;
  if(t<=time|| head==tail||head->next==NULL){
    head->waitingTime+=wait-head->waitingTime;
    tl+=wait+t;
    wait+=t;
    tw+=head->waitingTime;
    head->CPUBursttime=0;
    print(head,t);
    if(head==head->next){
      free(head);
      head=NULL;
    }
    else{
    struct PCB *a=head;
    head=head->next;
    free(a);}
  }
  else{
    
    head->waitingTime+=wait-head->waitingTime;
    wait+=time;
    head->CPUBursttime-=time;
    print(head,time);
    struct PCB *a=head;
    head=head->next;
    add(a);

  }
  
  
}
void input(struct PCB * a){
  int b;
  printf("Enter the CPUBursttime: ");
  scanf("%d",&b);
  a->CPUBursttime=b;
  a->waitingTime=0;
  a->next=NULL;
  add(a);
}
int main(){
  int n;
  printf("Enter the number of processes: ");
  scanf("%d",&n);
  struct PCB *temp;
  for(int i=0;i<n;i++){
    temp=malloc(sizeof(struct PCB));
    temp->pid=i;
    input(temp);
  }
  while(head!=NULL&&head->CPUBursttime !=0){
    run();
    
  }
  printf("Average Waiting Time:%f", (double)tw/n);
  printf("\nTurn Around Time:%d", tl);
}
