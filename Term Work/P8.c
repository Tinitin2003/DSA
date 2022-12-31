#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100
void merge(char** arr,int start,int mid,int end){
        int i,j,k;
        int n1=mid-start+1;
        int n2=end-mid;
        char** L=(char**)malloc(n1*sizeof(char*));
        char** R=(char**)malloc(n2*sizeof(char*));
        for(int i=0;i<n1;i++){
            L[i]=(char*)malloc(MAX*sizeof(char));
        }
        for(int i=0;i<n2;i++){
            R[i]=(char*)malloc(MAX*sizeof(char));
        }
        for(i=0;i<n1;i++){
            strcpy(L[i],arr[start+i]);
        }
        for(j=0;j<n2;j++){
            strcpy(R[j],arr[mid+1+j]);
        }
        i=0;
        j=0;
        k=start;
        while(i<n1 && j<n2){
            if(strcmp(L[i],R[j])<=0){
                strcpy(arr[k],L[i]);
                i++;
            }else{
                strcpy(arr[k],R[j]);
                j++;
            }
            k++;
        }

        while(i<n1){
            strcpy(arr[k],L[i]);
            i++;
            k++;
        }
        while(j<n2){
            strcpy(arr[k],R[j]);
            j++;
            k++;
        }
}
void merge_sort(char** arr,int start,int end){
    if(start<end){
        
        int mid=start+(end-start)/2;
        merge_sort(arr,start,mid);
        merge_sort(arr,mid+1,end);
        merge(arr,start,mid,end);
    }
}
int main(){
    int n;
    printf("Enter the number of  strings in array:");
    scanf("%d",&n);
    char** arr=(char**)malloc(n*sizeof(char*));
    for(int i=0;i<n;i++){
        arr[i]=(char*)malloc(MAX*sizeof(char));
    }
    printf("Enter the unsorted string:");
    for(int i=0;i<n;i++){
        scanf("%s",arr[i]);
    }
    merge_sort(arr,0,n-1);
    printf("Sorted array:\n");
    for(int i=0;i<n;i++){
        printf("%s ",arr[i]);
    }
}