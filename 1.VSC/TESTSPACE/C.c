#include<stdio.h>

typedef struct{
    int n;
    int arr[100][100];
}graph;

void init_graph(graph *a, int n){
    a->n = n;
    for(int i = 1 ;i<= a->n ;i++){
        for(int j = 1; j <= a->n; j++){
            a->arr[i][j] = 0;
        }
    }
}

void add_edge(graph *a, int u, int v, int type){
    if(type == 2){
        a->arr[u][v] = 1;
        a->arr[v][u] = 1;
    }
    else
        a->arr[u][v] = 1;
}

void dfs(graph* a, int n, int visited[]){
    visited[ n ] = 1;

    for(int i = 1; i <= a->n; i++){
        if( (a->arr[i][n] || a->arr[n][i]) && !visited[i]) dfs(a, i, visited);
    }
}

int main(){
    graph g;
    int m,n;
    scanf("%d%d",&n,&m);
    while(m-->= 1){
        int u, v, type;
        scanf("%d%d%d",&u,&v,&type);
        add_edge(&g, u, v, type);
    }
    int res = 1;
    
    int visited[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    
    //for(int i = 1; i <= n; i++){
       // if( !res ) break;
        dfs(&g, 1, visited);
        for(int i = 1; i <= n ; i++){
            if( visited[i] == 0) res = 0;
        }
    //}

    printf("%d ", res);
}