/*



j*/
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
void runTimeSharing(Process *head,int n) {
  Process *curr = head;
  int elapsedTime = 0;
  while (n) {
        while (n){
        if(head->remainingTime!=-1){
            if(head->remainingTime>=TIME_SLOT){
                head->remainingTime -= TIME_SLOT;
                elapsedTime += TIME_SLOT;
            }else{
                elapsedTime+=head->remainingTime;
                head->remainingTime=0;
            }

            if (head->remainingTime == 0){
                printf("Process %d completed after: %dns\n", head->id, elapsedTime);
                head->remainingTime=-1;
                n--;
            }
        }
        head=head->next;
    }
    printf("Total time taken: %dns\n",elapsedTime);
  }
}
int main(){
    Process* head=NULL;
    int n;
    printf("Enter number of processess:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        head=insert(head,i+1);
    }
    printf("CPU time:- 10ns\n\n");
    runTimeSharing(head,n);    

    return 0;
}