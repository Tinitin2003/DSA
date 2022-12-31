#include<stdio.h>
#include<stdlib.h>{
typedef struct node{
    int process;
    int time;
    struct node* next;
}node;
node* insert(node* head){
    node* p;
    int time,pro;
    p=(node*)malloc(sizeof(node));
    printf("Enter Process:");
    scanf("%d",&pro);
    printf("Enter time:");
    scanf("%d",&time);
    p->process=pro;
    p->time=time;
    p->next=NULL;
    if(head==NULL){
        head=p;
        head->next=head;
    }
    else{
        node* temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next=p;
        p->next=head;
    }
    return head;
}
void timetaken(node* head){
   int t=0;
   node* prev;
   node *temp=head;
   while(temp->next!=head){
    t=t+10;
    if(temp->time-10<=0){
        printf("%d process completed at %d\n",temp->process,t);
        if(temp->next==temp){
            break;
        }
        else{
            node *n=temp;
            temp=temp->next;
            free(n);
        }
    }
    else{
        temp->time=temp->time-10;
        prev=temp;
        temp=temp->next;
    }
   }
   t-=10;
   printf("Total time taken is %d millisecondes\n",t);
}
int main(){
    node* head=NULL;
    int ch;
    do{
        printf("Enter 1 for Insert\nEnter 2 to display time\nEnter 3 to exit\n");
        printf("Enter your choice:");
       scanf("%d",&ch);
       switch (ch){
      case 1: head=insert(head);
                break;
        case 2: timetaken(head);
                break;
        case 3: exit(0);
       }
    }while(1);

}