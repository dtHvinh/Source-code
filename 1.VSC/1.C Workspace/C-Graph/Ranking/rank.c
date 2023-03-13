#include <stdlib.h>
#include <stdio.h>

int in_deg[100];


struct node{
    int data;
    struct node* next;
};
typedef struct node* Queue;


// init_ queue
void makenullQueue(Queue *A){
    (*A) = (Queue)malloc(sizeof(Queue));
    (*A) -> next = NULL;
}


// check if queue is empty
int emptyQueue(Queue L) {
    return (L->next==NULL);
}

// add 1 element to Queue
void enQueue(Queue *A, int x){
    Queue temp;
    makenullQueue(&temp);
    Queue P = *A;
    while(P->next !=NULL){
        P=P->next;
    }
    temp->data = x;
    temp->next = P->next;
    P->next    = temp;
}

// pop the first element in a line
void deQueue(Queue *A){
    Queue temp,P=*A;
    temp=P->next; 
    P->next=temp->next; 
    free(temp);
}

// return the value of the very first element
int frontValue(Queue A){
    Queue P=A;
    return P->next->data;
} 
#include<stddef.h>
struct nodee{
    int data;
    struct nodee* next;
};
typedef struct nodee* List;
typedef List Pos;

void makenullList(List *L){
    (*L) =(List)malloc(sizeof(List));
    (*L)->next = NULL;
}

void insertList(int x,List *L){             //con tro bac 2
    List P = *L;
    while(P->next!=NULL){
        P=P->next;
    }
    List A;
    makenullList(&A);
    A->data = x;
    A->next = P->next;
    P->next = A;
}

Pos endList(List L){
    Pos pos;
    while(pos->next != NULL){
        pos = pos->next;
    }
    return pos;
}

void deleteList(List *L){
    Pos p = *L;
    while(p->next->next != NULL){
        p = p->next;
    }
    free(p->next);
    p->next = NULL;
}

int elementAt(List L,int x){
    List pos = L;
    if(x ==0) return pos->next->data;

    while (x-->=0)
    {
        pos = pos->next;
    }
    return pos->data;
    
}

int length(List L){
    List pos = L;
    int c = 0;
    while (pos->next != NULL)
    {
        pos = pos->next;
        c++;
    }
    return c;
}

typedef struct 
{
    int n;
    int arr[100][100];
}graph;

// initialize graph, in_deg array, and rank array.
void init_graph(graph *p, int n){
    p->n = n;
    for (size_t i = 1; i <= p->n; i++)
    {
        for (size_t j = 1; j <= p->n ; j++)
        {
            p->arr[i][j] = 0;
        }  
    }
    for(size_t i = 1; i <= p->n; i++) in_deg[i] = 0;
}


// add an edge to graph and
void add_edge(graph *g, int u, int v){
    g->arr[u][v] = 1;
    // increase in_deg[v] 1.
    in_deg[v]+=1;
}

List neighbors(graph *g, int x){
    List res;
    makenullList(&res);
    for (int i = 1; i <= g->n; i++)
    {
        if( g->arr[x][i] ) insertList(i,&res);
    }
    return res;
}


// void Vertices_ranking(graph a){
//     int rank[100];  for(size_t i = 1; i <= a.n; i++) rank[i] = 0;
//     int visited[100]; for(size_t i = 1; i <= a.n; i++) visited[i] = 0;
//     // Step No.
//     for(size_t i = 0; i < a.n; i++){

//         int decrease[a.n+1];
//         for(size_t k = 1; k <= a.n; k++) decrease[k] = 0;
        

//         for(size_t vertex = 1; vertex <= a.n; vertex++){
//             if(in_deg[vertex] == 0 && !visited){
//                 rank[vertex] = i;
//                 visited[vertex] =1;

//                 List list = neighbors(&a, vertex);
//                 for(size_t index = 0; index < length(list); index++){
//                     int temp = elementAt(list, index);
//                     decrease[ temp ] +=1;
//                 }
//             }
//         }
//         for(size_t k = 1; k <= a.n; k++) in_deg[k] -= decrease[k];
//     }

//     for(size_t i = 1; i <= a.n; i++) printf("%d ", rank[i]);
// }



int main(){
    freopen("testcase.txt", "r", stdin);
    graph g;
    int m,n;
    scanf("%d%d", &n, &m);
    init_graph(&g, n);
    while(m-->=1){
        int u, v;
        scanf("%d%d", &u, &v);
        add_edge(&g, u, v);
    }
    
    Vertices_ranking(g);

}
