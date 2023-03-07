#include<stdio.h>
#define inf 9999999

typedef struct{
    int max_vertex;
    int weight[100][100];
}graph;

/**
 * @brief Initialize a graph
 * @param g 
 */
void init_graph(graph *g, int max_vertex){
    g->max_vertex = max_vertex;
    for(int i = 1; i <= g->max_vertex; i++)
        for(int j = 1; j <= g->max_vertex; j++)
            g->weight[ i ][ j ] = 0;
}


void add(graph *g, int u, int v, int w){
    g->weight[u][v] = w;
}

void Dijkstra(graph *g, int s){
    // Keep track on all vertex
    int visited[g->max_vertex+1]; 
    // Previous`s vertex of each index_vertex.
    int previous[g->max_vertex+1];
    // Shortest path from 's' to each shortest[index].
    int shortest[g->max_vertex+1];
    for(int i = 1; i <= g->max_vertex; i++){
        visited[i] = 0;
        previous[i] = 0;
        shortest[i] = inf;
    }
    shortest[s] = 0 ;
    previous[s] = -1;

    for(size_t i = 1; i <= g->max_vertex; i++){
        // Each times. Find the shortest path which its vertex havent visited yet.
        int chosen_vertex;
        int min_path = inf;
        for(size_t vertex = 1; vertex <= g->max_vertex; vertex++){
            if( !visited[ vertex ] && shortest[ vertex ] < min_path){
                min_path      = shortest[ vertex ];
                chosen_vertex = vertex;
            }
        }
        
        // Mark the chosen ones.
        visited[ chosen_vertex ] = 1;

        for(size_t vertex = 1; vertex <= g->max_vertex; vertex++){
            // Update shortest path and its previous of the vertex WHICH hasn`t visited yet and has connection with chosen_vertex. 
            if( g->weight[ chosen_vertex ][ vertex ] && !visited[ vertex ]){
                if( shortest[ chosen_vertex ] + g->weight[ chosen_vertex ][ vertex ] < shortest[ vertex ]){
                    shortest[ vertex ] = shortest[ chosen_vertex ] + g->weight[ chosen_vertex ][ vertex ];
                    previous[ vertex ] = chosen_vertex;
                }
            }
        }

        for(size_t vertex = 1; vertex <= g->max_vertex ; vertex++){
            printf("Path from %d to %d = %d , Previous of %d is %d\n", s, vertex, shortest[ vertex ], vertex, previous[ vertex ]);
        }
    }
}




int main(){
    graph g;
    init_graph(&g, 6);
    add(&g, 1, 2, 7);
    add(&g, 1, 3, 1);
    add(&g, 2, 4, 4);
    add(&g, 2, 6, 1);
    add(&g, 3, 2, 5);
    add(&g, 3, 5, 2);
    add(&g, 3, 6, 7);
    add(&g, 5, 4, 5);
    add(&g, 5, 2, 2);
    add(&g, 6, 5, 3);  
    Dijkstra(&g, 1);
    return 0;
}

