#include<stdio.h>
#include<stdlib.h>{
typedef struct node{
    int info;
    struct node* next;
}node;
node* insert(node* head){
    node* p;
    int data;
    p=(node*)malloc(sizeof(node));
    scanf("%d",&data);
    p->info=data;
    p->next=NULL;
    if(head==NULL){
        head=p;
    }
    else{
        node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=p;
    }
    return head;
}
void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        printf("%d",temp->info);
        temp=temp->next;
    }
}
int main(){
    node* head=NULL;
    int ch;
    do{
            printf("Enter your choice:");
       scanf("%d",&ch);
       switch (ch){
      case 1: head=insert(head);
                break;
        case 2: display(head);
                break;
        case 3: exit(0);
       }
    }while(1);

}