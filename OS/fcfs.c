#include <stdio.h>
#include <stdlib.h>
struct PCB{
  int pid;
  int CPUBursttime;
  int waitingTime;
  struct PCB * next;
};
int time=0,wait=0,tw=0,tl=0;
void runfcfs(struct PCB * a){
  a->waitingTime=time;
  wait+=time;
  time+=a->CPUBursttime;
  tw+=wait;
  tl+=time;
  //a->CPUBursttime=0;
}
void input(struct PCB * a){
  int b;
  printf("Enter the CPUBursttime: ");
  scanf("%d",&b);
  a->CPUBursttime=b;
  a->next=NULL;
}
void print(struct PCB *a){
  printf("PID:%d\n",a->pid);
  printf("CPUBursttime:%d\n",a->CPUBursttime);
  printf("WaitingTime:%d\n",a->waitingTime);
}
int main(){
  int n;
  printf("Enter the number of processes: ");
  scanf("%d",&n);
  struct PCB * head=NULL,*temp;
  for(int i=0;i<n;i++){
    if(head==NULL){
      head=malloc(sizeof(struct PCB));
      head->pid=i;
      input(head);
      temp=head;
    }
    else{
      temp->next=malloc(sizeof(struct PCB));
      temp=temp->next;
      temp->pid=i;
      input(temp);
      
    }
  }
  temp=head;
  while(temp!=NULL){
    runfcfs(temp);
    temp=temp->next;
  }
  temp=head;
  while(temp!=NULL){
    print(temp);
    temp=temp->next;
  }
  printf("Average Waiting Time:%f",(double)tw/n);
  printf("\nAverage Turn Around time:%f",(float)tl/n);
}