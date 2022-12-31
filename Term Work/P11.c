//write a c program to implement Kurshkal's algorithm.
#include<stdio.h>
#include<stdlib.h>
#define MAX_VERTICES 100
#define MAX_EDGES 1000
typedef struct {
    int start;
    int end;
    int weight;
}Edge;
typedef struct{
    int parent;
    int rank;
}DisjointSet;
int findSet(DisjointSet *set,int x){
    if(set[x].parent!=x){
        set[x].parent=findSet(set,set[x].parent);
    }
    return set[x].parent;
}
void unionSet(DisjointSet *set,int x,int y){
    int xRoot=findSet(set,x);
    int yRoot=findSet(set,y);
    if(set[xRoot].rank<set[yRoot].rank){
        set[yRoot].parent=xRoot;
    }else{
        set[yRoot].parent=xRoot;
        set[xRoot].rank++;
    }
}

void makeSet(DisjointSet *set,int x){
    set[x].parent=x;
    set[x].rank=0;
}
int cmp(const void *a,const void *b){
    Edge *edgeA=(Edge*)a;
    Edge *edgeB=(Edge*)b;
    return edgeA->weight-edgeB->weight;
}
void kruskal(int numVertices,int numEdges,Edge *edges,Edge *result){
    qsort(edges,numEdges,sizeof(Edge),cmp);
    DisjointSet set[numVertices];
    for(int i=0;i<numVertices;i++){
        makeSet(set,i);
    }
    int resultIndex=0;
    for(int i=0;i<numEdges;i++){
        int u=edges[i].start;
        int v=edges[i].end;
        int weight=edges[i].weight;
        int uSet=findSet(set,u);
        int vSet=findSet(set,v);
        if(uSet!=vSet){
            result[resultIndex++]=edges[i];
            unionSet(set,uSet,vSet);
        }
    }
}
int main(){
    int numVertices,numEdges;
    printf("Enter the number of vertices and edges:");
    scanf("%d %d",&numVertices,&numEdges);
    Edge edges[MAX_EDGES];
    printf("Enter the edges(start, end, weight):\n");
    for(int i=0;i<numEdges;i++){
        scanf("%d %d %d",&edges[i].start,&edges[i].end,&edges[i].weight);
    }
    Edge result[MAX_VERTICES];
    kruskal(numVertices,numEdges,edges,result);
    printf("Minimum spanning tree:\n");
    for(int i=0;i<numVertices-1;i++){
        printf("%d %d %d\n",result[i].start,result[i].end,result[i].weight);
    }
    


}