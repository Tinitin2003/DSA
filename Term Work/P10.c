#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef struct node{
    int vertex;
    struct node* next;
}node;
typedef struct  graph
{
    int num_vertices;
    int* status;
    struct node** adj_list;
}graph;
graph* create_graph(int n){
    graph* g=(graph*)malloc(sizeof(graph));
    g->num_vertices=n;
    g->adj_list=(node**)malloc(n*sizeof(node*));
    g->status=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        g->adj_list[i]=NULL;
        g->status[i]=0;
    }
    return g;
}
void add_edge(graph* g,int source,int destination){
    node* new_node=(node*)malloc(sizeof(node));
    new_node->vertex=destination;
    new_node->next=NULL;
    new_node->next=g->adj_list[source];
    g->adj_list[source]=new_node;
}
void dfs(graph* graph,int source){
    graph->status[source]=1;
    printf("Visited vertex %d\n",source);
    node* temp=graph->adj_list[source];
    while(temp){
        int neighbour=temp->vertex;
        if(!graph->status[neighbour]){
            dfs(graph,neighbour);
        }
        temp=temp->next;
    }
}
void print_graph(graph* g){
        for(int i=0;i<g->num_vertices;i++){
            node* temp=g->adj_list[i];
            printf("Adaceny list for vertex %d: ",i);
            while(temp){
                printf("%d ->",temp->vertex);
                temp=temp->next;
            }
            printf("NULL\n");
        }    
}
int main(){
    graph* graph=create_graph(7);
    add_edge(graph,0,1);
    add_edge(graph,0,2);
    add_edge(graph,1,3);
    add_edge(graph,1,4);
    add_edge(graph,2,1);
    add_edge(graph,2,3);
    add_edge(graph,3,4);
    add_edge(graph,3,5);
    add_edge(graph,4,2);
    add_edge(graph,4,5);
    add_edge(graph,5,6);
    
    print_graph(graph);
    printf("DFS travesal of this graph is:\n");
    dfs(graph,0);
}
