#include<stdio.h>
#define MAX 100
int main(){
    int n;
    int arr[MAX];
    printf("Enter the number of elements in array:");
    scanf("%d",&n);
    printf("Enter the elements of array:");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Required array:");
    //Print all negative elements first
    for(int i=0;i<n;i++){
        if(arr[i]<0){
            printf("%d ",arr[i]);
        }
    }
    for(int i=0;i<n;i++){
        if(arr[i]>0){
            printf("%d ",arr[i]);
        }
    }


}