//Q=contains all elements in odd positon of p 
//P=remaining elements
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
void split(node** head,node** odd,node** even){
        node* temp=*head;
        int c=0;
        while(temp!=NULL){
            if(c%2==0){
                addtoEnd(&(*odd),temp->info);
            }
            else{
                    addtoEnd(&(*even),temp->info);
            }
            temp=temp->next;
            c++;
        }

}
int main(){
    node* P=NULL;
    node* Q=NULL;
    node* R=NULL;
    int n,val;
    printf("Enter Number of elements in Linked list:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&val);
        addtoEnd(&(P),val);
}
    printf("Entered original Linked list:");
    display(P);
    split(&P,&Q,&R);
    printf("Q(new) Linked list:");
    display(Q);
    printf("R(new) Linked list:");
    display(R);

}