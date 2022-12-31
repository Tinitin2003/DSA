#include<stdio.h>
#include<stdlib.h>
typedef struct node{
        struct node* left;
        int info;
        struct node* right;
}tree_type;
void insert(tree_type **rt,int val)
{
    tree_type* p;
    p=(tree_type*)malloc(sizeof(tree_type));
    p->info=val;
    p->left=NULL;
    p->right=NULL;
    if(*rt==NULL){
        *rt=p;
    }
    else{
        if((p->info)<((*rt)->info)){
            insert(&((*rt)->left),val);
        }
        else
        insert(&((*rt)->right),val);
    }
}
void search(tree_type* root, int key){
    if(root!=NULL){
        search(root->left,key);
        if(root->info==key){
            printf("Key element found:%d\n",key);
            return;
        }
        search(root->right,key);
    }
}
void preorder(tree_type* root){
    if(root!=NULL)
         {printf("%d\n",root->info);
         preorder(root->left);
         preorder(root->right);}
}

void num_leaf_nodes(tree_type* root,int *count){
    if(root!=NULL){
        if(root->left==NULL && root->right==NULL){
            (*count)++;
        }
        num_leaf_nodes(root->left,count);
        num_leaf_nodes(root->right,count);
    }
}
int maxDepth(tree_type* root){
    if(root==NULL){
        return 0;
    }else{
        int lDepth=maxDepth(root->left);
        int rDepth=maxDepth(root->right);
        if(lDepth>rDepth){
            return (lDepth+1);
        }
        else{
            return (rDepth+1);
        }
    }
}
int totalNodes(tree_type* root){
    if(root==NULL){
        return 0;
    }
    int r=totalNodes(root->right);
    int l=totalNodes(root->left);
    return l+r+1;
}
tree_type* inorderPredecessor(tree_type* root){
    root=root->left;
    while(root->right!=NULL){
        root=root->right;
    }
    return root;
}
tree_type* deleteNode(tree_type* root, int data) {
    tree_type* iPre;
  if (root == NULL) 
            return root;
    if(root->left==NULL && root->right==NULL){
        free(root);
        return NULL;
    }
  if (data < root->info)
            root->left = deleteNode(root->left, data);
  else if (data > root->info) 
            root->right = deleteNode(root->right, data);
  else {
    iPre=inorderPredecessor(root);
    root->info=iPre->info;
    deleteNode(root->left,iPre->info);
  }
  return root;
}

int main(){
        tree_type *root=NULL;
        int opt,total_nodes;
        int count_leaf,height;
        int val;
        tree_type *p=(tree_type*)malloc(sizeof(tree_type));
        do{
            printf("Enter your choice:");
            scanf("%d",&opt);
            switch(opt){
                case 1: printf("Enter the value:");
                        scanf("%d",&val);
                        insert(&root,val);
                        break;
                case 2:preorder(root);
                        break;
                case 3:search(root,10);
                        break;
                case 4:  count_leaf=0;
                        num_leaf_nodes(root,&count_leaf);
                        printf("%d\n",count_leaf);
                        break;
                case 5: height=maxDepth(root);
                        printf("Height of tree:%d\n",height);
                        break;
                case 6: total_nodes=totalNodes(root);
                        printf("Total number of nodes:%d\n",total_nodes);
                        break;
                case 7: printf("Enter the element to delete:");
                        scanf("%d",&val);
                        root=deleteNode(root,val); 
                        break;
                case 8: exit(0);
            }
        }while(1);
}