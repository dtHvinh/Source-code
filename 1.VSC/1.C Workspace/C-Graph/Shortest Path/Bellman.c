#include<stdio.h>
#define inf 99999

typedef struct{
    int u, v, w;
}edge;


typedef struct{
    int max_vertices;
    int max_edges;
    edge edges[100];
}Graph;

void init_Graph(Graph *G, int max_vertices);

void add(Graph *G, int u, int v, int w);

void Bellman_Algorithm(Graph *G, int starting_vertex){

    int path_to[ G->max_vertices+1];
    int pre_[ G->max_vertices+1];

    for (size_t i = 1; i <= G->max_vertices; i++){
        path_to[i] = inf;
        pre_[i] = 0;
    }
    
    path_to[ starting_vertex ] = 0;
    pre_[ starting_vertex ] = -1;
    for(size_t i = 1; i < G->max_vertices; i++){
        for(size_t edge = 0; edge < G->max_edges; edge++){
            int u = G->edges[ edge ].u;
            int v = G->edges[ edge ].v;
            int w = G->edges[ edge ].w;
            if(path_to[u] != inf && path_to[u] + w < path_to[v]){
                path_to[v] = path_to[u] + w;
                pre_[v] = u; 
            }
        }
    }

    for(size_t vertex = 1; vertex <= G->max_vertices ; vertex++){
        printf("Path from %d to %d = %d , Previous of %d is %d\n", starting_vertex, vertex, path_to[ vertex ], vertex, pre_[ vertex ]);
    }
}

int main(){
    Graph G;
    int m;
    
    init_Graph(&G, 6);
    
    add(&G, 1, 2, 7);
    add(&G, 1, 3, 1);
    add(&G, 2, 4, 4);
    add(&G, 2, 6, 1);
    add(&G, 3, 2, 5);
    add(&G, 3, 5, 2);
    add(&G, 3, 6, 7);
    add(&G, 5, 4, 5);
    add(&G, 5, 2, 2);
    add(&G, 6, 5, 3);   

    Bellman_Algorithm(&G, 1);
}







/// Function implementation.
void init_Graph(Graph *G, int max_vertices){
    G->max_edges = 0;
    G->max_vertices = max_vertices;
}

void add(Graph *G, int u, int v, int w){
    G->edges[ G->max_edges ].u = u;
    G->edges[ G->max_edges ].v = v;
    G->edges[ G->max_edges ].w = w;
    G->max_edges++; 
}




/* Bug recorder
    Hàm add sai  G->edges[ G->max_vertex ].u = u thay vì G->edges[ G->max_edges ].u = u;
*/