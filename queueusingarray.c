#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    struct node * next;
    int info;
}node;

node* insert (node* head){
node*p;int val;
p= (node*)malloc(sizeof(node));
scanf("%d",&val);
p->info=val;
p->next=NULL;

if(head==NULL){
    head=p;
}
else {
    node*temp;
    temp = head;
    while(temp->next!=NULL){
        temp=temp ->next;
        
    } 
     temp->next=p;

}
return head;
}
void display (node * head)
{
node* temp;
temp=head;
while(temp!=NULL){
    printf("%d ",temp->info);
    temp=temp->next;
}
}


int main(){

    int ch, val;
    node*head=NULL;
    do {
        printf("press 1 for insert\n press 2 for delete \n press 3 for display \n press 4 for exit\n");
        scanf("%d",&ch);

        switch(ch) {

            case 1 :head= insert (head);
                     break;
            //case 2 : head =delete (head);
              //      break;
            case 3 : display(head);
                    break;
            case 4: exit(0);
        }
    }while(1);
    return 0;
}
