#include<stdio.h>
#include"D:\Code\Main\Source-Code\1.VSC\1.C Workspace\C-List\List.c"

typedef struct 
{
    int n;
    int arr[100][100];
}graph;


void init_graph(graph *p, int n){
    p->n = n;
    for (size_t i = 1; i <= p->n; i++)
    {
        for (size_t j = 1; j <= p->n ; j++)
        {
            p->arr[i][j] = 0;
        }  
    }
}

// add an edge to graph
void add_edge(graph *g, int u, int v){
    g->arr[u][v] = 1;
    // add the line under if non-direct graph
    g->arr[v][u] = 1;
}

List neighbors(graph *g, int x){
    List res = makenullList(&res);
    for (int i = 0; i <= g->n; i++)
    {
        if(g->arr[x][i] != 0) insertList(i,&res);
    }
    return res;
}






