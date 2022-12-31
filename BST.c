#include<stdio.h>
#include<stdlib.h>
typedef struct node{
        struct node* left;
        int info;
        struct node* right;
}tree_type;
void insert(tree_type **rt,tree_type *p)
{
    if(*rt==NULL){
        *rt=p;
    }
    else{
        if((p->info)<((*rt)->info)){
            insert(&((*rt)->left),p);
        }
        else
        insert(&((*rt)->right),p);
    }
}
void preorder(tree_type* root){
    if(root!=NULL){
         printf("%d\n",root->info);
    preorder(root->left);
    preorder(root->right);
    }
}
int main(){
        tree_type *root=NULL;
        int opt;
        int val;
        tree_type *p=(tree_type*)malloc(sizeof(tree_type));
        do{
            printf("Enter your choice:");
            scanf("%d",&opt);
            switch(opt){
                case 1: printf("Enter the value:");
                        scanf("%d",&val);
                        p->info=val;
                        p->left=NULL;
                        p->right=NULL;
                        insert(&root,p);
                        break;
                case 2:preorder(root);
                        break;
                case 3: exit(0);
            }
        }while(1);
}