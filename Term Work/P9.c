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
    struct node** adj_list;
}graph;
graph* create_graph(int n){
    graph* g=(graph*)malloc(sizeof(graph));
    g->num_vertices=n;
    g->adj_list=(node**)malloc(n*sizeof(node*));
    for(int i=0;i<n;i++){
        g->adj_list[i]=NULL;
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
    graph* graph=create_graph(4);
    add_edge(graph,0,1);
    add_edge(graph,0,2);
    add_edge(graph,0,3);
    add_edge(graph,1,3);
    print_graph(graph);
}
