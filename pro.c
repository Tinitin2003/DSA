#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int src;
    int time;
}node;
void input(node *req){
        req=(node*)malloc(sizeof(node)*2);
    for(int i=0;i<2;i++){
        scanf("%d",&req[i].src);
        scanf("%d",&req[i].time);
    }
}
void output(node *req){
    for(int i=0;i<2;i++){
        printf("%d ",req[i].src);
        printf("%d ",req[i].time);
        printf("\n");
    }
}
int main(){
    node *req;

    input(req);
    output(req);
}