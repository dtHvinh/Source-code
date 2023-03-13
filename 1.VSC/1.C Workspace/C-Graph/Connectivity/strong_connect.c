#include<stdbool.h>
#include<stddef.h>
#include<stdio.h>

#define MAX_VALUE 9999
#define enter printf("\n")

int min(int a, int b) { return a > b ? b : a;}



// Implementation of a list data structure using an array.
typedef struct{
    int l_i;
    int arr[ MAX_VALUE ];
}list;

typedef list stack;

int  element_at(list *L, int position);
void makenull(list *L);
void push(list *L, int value);
void pop(list *L);

bool isEmpty(stack *L);
int  top(stack *L);




// Directed graph with adjacency list implementation.
typedef struct 
{
    int u, v;
}edge; 

typedef struct{
    int m_v;                    // Max vertices in Graph.
    int c_e;                    // The current number of edges in Graph. @note This value subtracts 1 to get the index of the last edge.
    edge edges[ MAX_VALUE ];    // Array of edges in the Graph.
}Graph;



void init_Graph(Graph *G, int m_v);
list neighbors(Graph *G, int vertex);
void add(Graph *G, int s, int e);


// Strong connect components algorithm Implementation.
void strong_connect(Graph *G, int cur_ver, int *k, int num[], int min_num[], stack *st, int on_stack[]);

void scc(Graph *G);

// Main function.
int main(){
    Graph G;
    init_Graph(&G, 8);

    add(&G, 1, 2);
    add(&G, 1, 3);
    add(&G, 2, 1);
    add(&G, 2, 8);
    add(&G, 3, 4);
    add(&G, 3, 5);
    add(&G, 4, 2);
    add(&G, 4, 7);
    add(&G, 4, 8);
    add(&G, 5, 3);
    add(&G, 5, 7);
    add(&G, 6, 7);
    add(&G, 7, 6);
    add(&G, 8, 7);

    scc(&G);



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

/// @brief Return the value at the top (end) of the stack (List)
/// @param L Input List
/// @return Top element value.
int top(list *L){ return L->arr[ L->l_i-1 ]; }

/// @brief Check whether the Stack is empty.
/// @param L Input List.
/// @return "1" if empty or "0". 
bool isEmpty(list *L){ return !L->l_i; }

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
void init_Graph(Graph *G, int m_v){
    G->c_e = 0;
    G->m_v = m_v;
}

/// @brief Add an edge to The Graph.
/// @param G Input Graph.
/// @param s Input the start Vertex.
/// @param e Input the end Vertex. 
/// @param w Input the weight of path from "s" to "e".
void add(Graph *G, int s, int e){
    G->edges[ G->c_e ].u = s;
    G->edges[ G->c_e ].v = e;
    G->c_e++;
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


void strong_connect(Graph *G, int cur_ver, int *k, int num[], int min_num[], stack *st, int on_stack[]){
    num[cur_ver]= min_num[cur_ver] = *k;
    *k += 1;

    push(st, cur_ver);
    on_stack[ cur_ver ]= 1;
    

    list list = neighbors(G, cur_ver);

    for(size_t index = 0; index < list.l_i; index++){
        int vertex = element_at(&list, index);
        if( num[ vertex ] == -1){
            strong_connect(G, vertex, k, num, min_num, st, on_stack);
            min_num[cur_ver] = min( min_num[cur_ver], min_num[vertex]);
        }
        else if( on_stack[vertex] ){
            min_num[cur_ver] = min( min_num[cur_ver], num[vertex]);
        }
    }

    if( min_num[cur_ver] ==  num[cur_ver] ){
        int w;
        do{
            w = top(st); pop(st);
            printf("%d ", w);
            on_stack[cur_ver] = 0;
        }while( w != cur_ver);
        printf("\n");
    }
}

void scc(Graph *G){
    int num[G->m_v +1];
    int min_num[G->m_v +1];
    int on_stack[G->m_v +1];

    for(size_t i = 1; i <= G->m_v; i++){
        num[i] = -1;
        min_num [i] = 0;
        on_stack[i] = 0;
    }
    int k = 1;

    stack st;
    makenull(&st);
    for(size_t vertex = 1; vertex <= G->m_v; vertex++){
        if( num[ vertex ] == -1){
            strong_connect(G, vertex, &k, num, min_num, &st, on_stack);
        }
    }
}