#include<stdio.h>
#include<stdlib.h>
#define max 30 
int push(int arr[] , int top){
        int a;
     if(top==max-1){
         
         printf("stack is overflow");
         
     }
     else {
         printf("enter a value \n");
         scanf("%d",&a);
         
         top = top +1 ;
         arr[top]=a;
     }
 return top;

}
int pop (int arr[] , int top){
     
     if(top==-1){
         printf("stack is underflow");
         
     }
     else {
         top = top -1;
     }
    return top;

}
void display(int arr[],int top ){
    printf("elements of array ");
for(int i =0;i<5;i++){
    printf("%d ",arr[i] );

}
printf("\n");
    }
int main(){
    int arr[5]=0;
    int ch, i, top=-1, a ;
    do {
    printf("press 1 for pop\n press 2 for push\n press 3 for display\n press 4 for exit\n");
    scanf("%d",&ch);
    switch(ch){
     case 1 : top=pop(arr,top);
             break;
     case 2 : top=push(arr,top);         
             break;
     case 3 : display (arr,top);        
             break;
      case 4 : exit(0);
}printf("elements of array ");
for(int i =0;i<5;i++){
    printf("%d ",arr[i] );

}
printf("\n");
}while(1);




}
