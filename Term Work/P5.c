#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define TIME_SLOT 10
typedef struct node{
    int id;
    int burstTime;
    int remainingTime;
    struct node* next;
}Process;
Process* insert(Process* head,int i){
    Process* p;
    int t;
    p=(Process*)malloc(sizeof(Process));
    p->id=i;
    printf("Enter Burst time for process %d: ",p->id);
    scanf("%d",&t);
    p->burstTime=t;
    p->remainingTime=t;
    p->next=NULL;
    if(head==NULL){
        head=p;
        head->next=head;
    }
    else{
        Process* temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next=p;
        p->next=head;
    }
    return head;
}
void runTimeSharing(Process *head) {
  Process *curr = head;
  int elapsedTime = 0;
  while (true) {
    if (curr->remainingTime <= TIME_SLOT) {
      elapsedTime += curr->remainingTime;
      printf("Process %d completed in %dns\n", curr->id, elapsedTime);
      Process *temp = curr;
      curr = curr->next;
      if (curr == head) {
        break;
      }
      temp->next = NULL;
      free(temp);
    } else {
      elapsedTime += TIME_SLOT;
      curr->remainingTime -= TIME_SLOT;
      curr = curr->next;
    }
  }
}

void main(){
    Process* head=NULL;
    int n;
    printf("Enter number of processess:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        head=insert(head,i+1);
    }
    runTimeSharing(head);    
}