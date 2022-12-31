#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    struct node* prev;
    int info;
    struct node* next;
}node;
node* create(int val){

    node *new;
    new=(node*)malloc(sizeof(node));
    new->prev=NULL;
    new->info=val;
    new->next=NULL;
    return new;
}
void addtoEnd(node** head,int val){
    node* new_node=create(val);
    node* current;
    if(*head==NULL){
        *head=new_node;
    }
    else if((*head)->info>=new_node->info){
        new_node->next=*head;
        (*head)->prev=new_node;
        (*head)=new_node;
    }else{
        current=*head;
        while(current->next!=NULL && current->next->info<new_node->info){
            current=current->next;
        }
        new_node->next=current->next;
        if(current->next!=NULL){
            new_node->next->prev=new_node;
        }
        current->next=new_node;
        new_node->prev=current;
    }
}
void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        printf("%d ",temp->info);
        temp=temp->next;
    }
    printf("\n");
}

int main(){
    node *dhead=NULL;
    int n,val;
    printf("Enter the number of elements  in linked list:");
    scanf("%d",&n);
    printf("Enter the elements:");
    for(int i=0;i<n;i++){
        scanf("%d",&val);
        addtoEnd(&(dhead),val);
    }
    display(dhead);
}