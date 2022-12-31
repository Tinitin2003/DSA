#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* next;
}node;
node* insert(node** head){
    node* p;
    int info;
    p=(node*)malloc(sizeof(node));
    printf("Enter data:");
    scanf("%d",&info);
    p->data=info;
    p->next=NULL;
    if(*head==NULL){
        (*head)=p;
    }
    else{
        node* temp;
        temp=head;
        while((temp)->next!=NULL){
            temp=temp->next;
        }
        temp->next=p;

    }
    return head;
}
void display(node* head){
        node* temp=head;
        while(temp!=NULL){
            printf("%d",temp->data);
            temp=temp->next;
        }
}
int main(){
    node* head=NULL;
    int ch;
    do{
        printf("Enter 1 for insertion\nEnter 2 for Display\nEnter 3 for mergesort\n");
        printf("Enter the choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1: head=insert(head);
                    break;
            case 2: display(head);
        }

    }while(1);

}