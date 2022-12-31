#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int coeff;
    int exp;
    struct node* next;
}node;
void addtoList(node** head,int c,int d){
    node* p=(node*)malloc(sizeof(node));
    p->coeff=c;
    p->exp=d;
    p->next=NULL;
    if(*head==NULL){
        *head=p;
    }
    else{
        node* temp=*head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=p;
    }
}
void addPoly(node** head,node* p1,node*p2,int i){
    node*p=(node*)malloc(sizeof(node));
    p->coeff=p1->coeff+p2->coeff;
    p->exp=i;
    p->next=NULL;
     if(*head==NULL){
        *head=p;
    }
    else{
        node* temp=*head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=p;
    }
}
void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        printf("%dx%d ",temp->coeff,temp->exp);
        temp=temp->next;
    }
}
int main(){
        node* p1=NULL;
        node* p2=NULL;
        node* p=NULL;
        int n,c,e;
        printf("Enter the degree of polonomial:");
        scanf("%d",&n);
        printf("Enter the first polonomial:\n");
        for(int i=0;i<n;i++){
            printf("Enter the constant for degree %d:",i);
            scanf("%d",&c);
            addtoList(&(p1),c,i);
        }
        printf("\n");
        printf("Enter the second polonomial:\n");
        for(int i=0;i<n;i++){
            printf("Enter the constant for degree %d:",i);
            scanf("%d",&c);
            addtoList(&(p2),c,i);
        }
        node* temp1=p1;
        node* temp2=p2;
        for(int i=0;i<n;i++){
             addPoly(&(p),temp1,temp2,i);
             temp1=temp1->next;
             temp2=temp2->next;
        }
       
        printf("The resultant polynomial:");
        display(p);
}