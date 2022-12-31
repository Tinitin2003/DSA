//Create positive and negative from original linked list
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int info;
    struct node* next;
}node;
node* create(int val){
    node *new;
    new=(node*)malloc(sizeof(node));
    new->info=val;
    new->next=NULL;
    return new;
}
void addtoEnd(node** head,int val){
    node* new_node=create(val);
    if(*head==NULL){
        *head=new_node;
    }
    else{
        node* temp=*head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new_node;
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
void split(node** head,node** positive,node** negative){
        node* temp=*head;
        while(temp!=NULL){
            if(temp->info<0){
                addtoEnd(&(*negative),temp->info);
            }
            else if(temp->info>0){
                    addtoEnd(&(*positive),temp->info);
            }
            temp=temp->next;
        }

}
int main(){
    node* head=NULL;
    node* positive=NULL;
    node* negative=NULL;
    int n,val;
    printf("Enter Number of elements in Linked list:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&val);
        addtoEnd(&(head),val);
}
    printf("Entered original Linked list:");
    display(head);
    split(&head,&positive,&negative);
    printf("Positive(new) Linked list:");
    display(positive);
    printf("Negative(new) Linked list:");
    display(negative);

}