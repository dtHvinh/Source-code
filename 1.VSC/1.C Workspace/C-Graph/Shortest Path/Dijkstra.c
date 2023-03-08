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


/* Duoi day la cai dat dung
#include<stdio.h>
#define NO_EDGE 0

typedef struct {
	int n;
	int L[100][100];
}graph;

void init_graph(graph* G, int n) {
	G->n = n;
 	int i, j;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			G->L[i][j] = NO_EDGE;
}

void add(graph *p, int u, int v, int w){
	p->L[u][v] = w;
}

#define MAXN 100
#define INFINITY 9999
int mark[MAXN];
int pi[MAXN];
int p[MAXN];

void Dijkstra(graph* G, int s) {
	 int i, j, it;
	 
	 for (i = 1; i <= G->n; i++) {
		mark[i] = 0;
	 	if(i != s) pi[i] = INFINITY;
	 }
	 pi[s] = 0;
	 
	 p[s] = 0;
	 for (it = 0; it < G->n; it++) {
	 int min_pi = INFINITY;
		for (j = 1; j <= G->n; j++)
			 if (mark[j] == 0 && pi[j] < min_pi) {
				 min_pi = pi[j];
				 i = j;
			 }
	 	mark[i] = 1;
		 for (j = 1; j <= G->n; j++){
			 if (G->L[i][j] != NO_EDGE && mark[j] == 0) {
				 if (pi[i] + G->L[i][j] < pi[j]) {
				 	pi[j] = pi[i] + G->L[i][j];
				 	p[j] = i;
				 }
			 }
		}
	 }

    for(size_t vertex = 1; vertex <= G->n ; vertex++){
        printf("Path from %d to %d = %d , Previous of %d is %d\n", s, vertex, pi[ vertex ], vertex, p[ vertex ]);
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
*/




