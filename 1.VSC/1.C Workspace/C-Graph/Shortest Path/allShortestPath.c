/// @warning All implementations assume that the input vertex does not exceed 100, and the weight between 2 vertices does not exceed 100.

#include<stdbool.h>
#include<stddef.h>
#define MAX_VALUE 9999
#define enter printf("\n")

// Implementation of a list data structure using an array.
typedef struct{
    int l_i;
    int arr[ MAX_VALUE ];
}list;

int  element_at(list *L, int position);
void makenull(list *L);
void push(list *L, int value);
void pop(list *L);


// Directed graph with adjacency list implementation.
typedef struct 
{
    int u, v;
    int w;
}edge; 

typedef struct{
    int m_v;                    // Max vertices in Graph.
    int c_e;                    // The current number of edges in Graph. @note This value subtracts 1 to get the index of the last edge.
    edge edges[ MAX_VALUE ];    // Array of edges in the Graph.
}Graph;



void makenullGraph(Graph *G, int m_v);
list neighbors(Graph *G, int vertex);
int  weight(Graph *G, int s, int e);
void add(Graph *G, int s, int e, int w);

// All shortest path algorithm.

void FloydWarshall_Algorithm(Graph *G);
void Dijkstra_Algorithm(Graph *G, int starting_point);
void Bellman_Algorithm(Graph *G, int starting_point);

// Main() function.
#include<stdio.h>

int main(){
    Graph G;
    makenullGraph(&G, 6);
    
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

    Dijkstra_Algorithm(&G, 3);
}
















// Function.

/// @brief Initialize the list.
/// @param L Input List.
void makenull(list *L){ L->l_i = 0; };

/// @brief Add an element at the end of the list.
/// @param L Input List.
/// @param value That Element`s value.
void push(list *L, int value){
    L->arr[ L->l_i ] = value;
    L->l_i++;
}

/// @brief Delete an element at the end of the %List.
/// @param L Input List.
void pop(list *L){
    if( !L->l_i ){
        printf("The List already empty!");
        return;
    }
    L->l_i--;
}

/// @brief Represent the value of position.
/// @param L Input List.
/// @param position Input position.
/// @return Value of the elemnt at that position in the List.
int element_at(list *L, int position){
    if( position >= L->l_i){
        printf("Out of bound. ");
        return -1;
    }
    return L->arr[ position ];
}

/// @brief Initialize the Graph.
/// @param G Input Graph.
/// @param m_v Input max vertices.
void makenullGraph(Graph *G, int m_v){
    G->c_e = 0;
    G->m_v = m_v;
}

/// @brief Add an edge to The Graph.
/// @param G Input Graph.
/// @param s Input the start Vertex.
/// @param e Input the end Vertex. 
/// @param w Input the weight of path from "s" to "e".
void add(Graph *G, int s, int e, int w){
    G->edges[ G->c_e ].u = s;
    G->edges[ G->c_e ].v = e;
    G->edges[ G->c_e ].w = w;
    G->c_e++;
}

/// @brief Return the weight of (s) and (e) vertex.
/// @param G Input Graph.
/// @param s Input vertex 1.
/// @param e Input vertex 2.
/// @return Return (s) and (e) weight if they have connection or "0".
int weight(Graph *G, int s, int e){
    for(size_t index = 0; index < G->c_e; index++){
        int u = G->edges[ index ].u;
        int v = G->edges[ index ].v;
        if( u == s && v == e ) return  G->edges[ index ].w;
    } 
    return 0;
}

/// @brief Return a /list/ of adjacent vertices for the Input /vertex/ in the adjacency list representation of the /graph/.
/// @param G Input Graph
/// @param vertex Input vertex.
/// @return list.
list neighbors(Graph *G, int vertex){
    list res; makenull(&res);

    for(size_t index = 0; index < G->c_e; index++){
        int u = G->edges[ index ].u;
        int v = G->edges[ index ].v;
        /// Because the Graph is an directed Graph so this only allow u-->v.
        if( u == vertex ) push(&res, v);
    } 

    return res;
}

/// @brief Print the shortest path from starting_point (s_p) to all reachable vertices.
/// @details This algorithm works by looping through the vertices of the graph a maximum of max_vertices times. 
///          During each iteration, it chooses the unvisited vertex with the shortest path from s_p, and then
///          relaxes every neighbor of that vertex that satisfies certain conditions.
/// @param G Input Graph.
/// @param s_p Input starting point.
void Dijkstra_Algorithm(Graph *G, int s_p){
    // Keep track of visited vertices.
    int visited[ G->m_v+1 ];
    // Currently shortest path from starting point (s_p) to each index vertex.
    int path_to[ G->m_v+1 ];
    // The vertex before index vertex.
    int prev_of[ G->m_v+1 ];
    // Initialize these 3 array.
    for(size_t vertex = 1; vertex <= G->m_v; vertex++){
        visited[ vertex ] = prev_of[ vertex ] = 0;
        path_to[ vertex ] = MAX_VALUE;
    }
    // Initialize starting_point (s_p) characteristics.
    path_to[ s_p ] = 0;
    prev_of[ s_p ] = -1;
    // Loop /max_vertices/ times.
    for(size_t loop = 1; loop < G->m_v; loop++)
    {
        int c_v;                     // The chosen vertex that has the shortest path from starting point (s_p) to the chosen vertex (c_v); 
        int min_path = MAX_VALUE;    // That shortest path value.
        // Each times, Find the shortest path which its vertex hasn`t visited yet.
        for(size_t vertex = 1; vertex <= G->m_v; vertex++)
            if( !visited[ vertex ] && path_to[ vertex ] < min_path)
            {
                min_path = path_to[ vertex ];
                c_v      = vertex; 
            }
        // Mark chosen vertex (c_v) is visited.
        visited[ c_v ] = 1;
        // Relax all chosen vertex neighbors.
        list list = neighbors(G, c_v);
        for(size_t index = 0; index < list.l_i; index++)
        {
            int cur_v = element_at(&list, index);
            if( !visited[ cur_v ] && path_to[ c_v ] + weight(G, c_v, cur_v) < path_to[ cur_v ])
            {
                path_to[ cur_v ] = path_to[ c_v ] + weight(G, c_v, cur_v);
                prev_of[ cur_v ] = c_v;
            }
        }
    } 
    for(size_t vertex = 1; vertex <= G->m_v; vertex++)
    printf("Path from %d to %d = %d , The vertex previous to %d is %d.\n", s_p, vertex, path_to[ vertex ], vertex, prev_of[ vertex ]);
}

/// @brief Print the shortest path from starting_point (s_p) to all reachable vertices.
/// @details This algorithm works by looping through all the edges of the graph a maximum of max vertices (m_v) times. 
///          During each iteration, it relaxes every vertex related to that edge if certain conditions are satisfied.
/// @param G Input Graph.
/// @param s_p Input starting point.
void Bellman_Algorithm(Graph *G, int s_p){
    // Currently shortest path from starting point (s_p) to each index vertex.
    int path_to[ G->m_v+ 1 ];
    // The vertex before index vertex.
    int prev_of[ G->m_v+ 1 ];
    // Initialize these 3 array.
    for(size_t vertex = 1; vertex <= G->m_v; vertex++){
        path_to[ vertex ] = MAX_VALUE;
        prev_of[ vertex ] = 0;
    }
    // Initialize starting_point (s_p) characteristics.
    path_to[ s_p ] = 0;
    prev_of[ s_p ] = -1;
    // Loop /max_vertices/ times and start the relaxation.
    size_t times = 1;
    while( times++ <= G->m_v)
    for(size_t index = 0; index < G->c_e; index++){
        int u = G->edges[ index ].u;
        int v = G->edges[ index ].v;
        int w = weight(G, u, v);
        if( path_to[ u ] != MAX_VALUE && path_to[ u ] + w < path_to[ v ] ){
            path_to[ v ] = path_to[ u ] + w;
            prev_of[ v ] = u;
        } 
    }
    // Check whether the graph has negative cycle.
    bool has_negative_cycle = false;
    while( times++ <= G->m_v && !has_negative_cycle)
    for(size_t index = 0; index < G->c_e; index++){
        int u = G->edges[ index ].u;
        int v = G->edges[ index ].v;
        int w = weight(G, u, v);
        if( path_to[ u ] != MAX_VALUE && path_to[ u ] + w < path_to[ v ] ){
            has_negative_cycle = true;
        } 
    }
    // Print the result.
    if(!has_negative_cycle)
        for(size_t vertex = 1; vertex <= G->m_v; vertex++)
            printf("Path from %d to %d = %d , The vertex previous to %d is %d.\n", s_p, vertex, path_to[ vertex ], vertex, prev_of[ vertex ]);
    else    
            printf("Negative cycle detected!.");
}

void FloydWarshall_Algorithm(Graph *G){
    // Create a adjacency matrix with given Graph.
    int matrix[ G->m_v +1 ][ G->m_v +1];
    // Initialize matrix default value.
    for(size_t i = 1; i <= G->m_v; i++) for(size_t j = 1; j <= G->m_v; j++) matrix[i][j] = MAX_VALUE;

    for(size_t index = 0 ; index < G->c_e; index++){
        int u = G->edges[ index ].u;
        int v = G->edges[ index ].v;
        matrix[ u ][ v ] = G->edges[ index ].w;
    }

    for(size_t vertex2 = 1; vertex2 <= G->m_v; vertex2++)
        for(size_t vertex1 = 1; vertex1 <= G->m_v; vertex1++)
            for(size_t vertex3 = 1; vertex3 <= G->m_v; vertex3++)
                if( matrix[vertex1][vertex2] + matrix[vertex2][vertex3] < matrix[vertex1][vertex3]){
                    matrix[vertex1][vertex3] = matrix[vertex1][vertex2] + matrix[vertex2][vertex3];
                }

    for(size_t vertex1 = 1; vertex1 <= G->m_v; vertex1++){
        for(size_t vertex2 = 1; vertex2 <= G->m_v; vertex2++){
            if( matrix[vertex1][vertex2] < MAX_VALUE) printf("Path from %d to %d = %d.\n", vertex1, vertex2, matrix[vertex1][vertex2]);
        }
        enter;    
    }
}



/* Bug record
 * 
 * 1. missed !visited[i] condition.
 * 
 * 2. weight(&G,...) instead of weight(G,...) make the function error.
 * 
 * Remember that initialize path_to all vertices as inf instead of "0". 
 * 
*/


