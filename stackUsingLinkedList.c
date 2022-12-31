#include<stdio.h>
#include<stdlib.h>{
typedef struct node{
    int info;
    struct node* next;
}node;
node* insert(node* top){
    node* p;
    int data;
    p=(node*)malloc(sizeof(node));
    scanf("%d",&data);
    p->info=data;
    p->next=NULL;
    if(top==NULL){
        top=p;
    }
    else{
       p->next=top;
       top=p;
    }
    return top;
}
void display(node* top){
    if(top==NULL){
        printf("underflow");
    }
    else{
    node* temp=top;
    while(temp!=NULL){
        printf("%d",temp->info);
        temp=temp->next;
    }}
}
int main(){
    node* top=NULL;
    int ch;
    do{
            printf("Enter your choice:");
       scanf("%d",&ch);
       switch (ch){
      case 1: top=insert(top);
                break;
        case 2: display(top);
                break;
        case 3: exit(0);
       }
    }while(1);

}