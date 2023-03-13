#include <stdio.h>
#define MAX_Length 20
#define MAX_ELEMENTS 100
#define MAX_VERTEXES 100
typedef struct {
    int data[MAX_ELEMENTS];
    int front, rear;
} Queue;
void make_null_queue(Queue* Q) {
    Q->front = 0;
    Q->rear = -1;
}
void push(Queue* Q, int x) {
    Q->rear++;
    Q->data[Q->rear] = x;
}
int top(Queue* Q) {
    return Q->data[Q->front];
}
void pop(Queue* Q) {
    Q->front++;
}
int empty(Queue* Q) {
    return Q->front > Q->rear;
}

typedef struct 
{
    /* data */
    int u, v; // u = dinh 1, v = dinh 2
}edge;

// List 
typedef struct 
{
    int data[MAX_Length];
    int size;
}list;

void makeNull(list *L){
    L->size = 0;
}
int elementAt(list *L, int x){
    return L->data[x];
}
void pushList(list *L, int x){
    L->data[L->size] = x;
    L->size++;
}

// Gtaph 
typedef struct 
{
    /* data */
    int n, m; // n = so dinh, m = so canh
    edge data[MAX_Length]; // e = tap hop cac canh
}graph;

void initGraph(graph *G, int n){
    G->n = n;
    G->m = 0;
}

void addEdge(graph *G, int u, int v){
    G->data[G->m].u = u;
    G->data[G->m].v = v;
    G->m++;
} 

int adjacent(graph *G, int u, int v){
    int i;
    for(i = 0; i<=G->m; i++){
        if (G->data[i].u == u && G->data[i].v == v){
            return 1;
        }
    }
    return 0;
}


list neighbors(graph *G, int x){
    list listVertex;
    makeNull(&listVertex);
    int i;
    for(i = 1; i<=G->n; i++){
        if (adjacent(G, x, i) == 1)
        {
            pushList(&listVertex, i);
        }
    }
    return listVertex;
}


/**
 * @brief Kiem Tra Chu trinh tu dinh bat dau o den tat ca cac dinh con lai.
 * @param G Do thi.
 * @param o Dinh bat dau.
 * @param *p Mang danh dau da xet.
 * @param *cycle Cap nhat ket qua "0/1".
*/
void breath_first_search(graph* G,int o, int *p, int *cycle) {
	Queue L;
	make_null_queue(&L);
	
	push(&L, o);

	*(p+o) = 1;

	while (!empty(&L)) {

		int x = top(&L); pop(&L);

		list a = neighbors(G, x);

		int m;
		for (m = 0; m < a.size; m++) {
			int y = elementAt(&a, m);
			if (*(p+y) == 0) { 
				*(p+y) = 1; 
				push(&L, y); 
			}
			else{
			    *cycle = 1;
			    break;
			}
		}
	}
	// Reset lai toan bo mang da danh dau va chi danh dau phan tu bat dau.
	for(int i = 1; i <= G->n; i++){
	    *(p+i) = 0; 
	}
	*(p+o) = 1;
	//
}


int main(){
    graph a;
    int m,n;
    scanf("%d%d",&n,&m);
    initGraph(&a,n);
    while(m--> 0){
        int u,v;
        scanf("%d%d",&u,&v);
        addEdge(&a,u,v);
    }
    
    // Bien ghi gia tri ket qua.
    int cycle = 0;
    
    // Mang danh dau.
    int mark[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    
    for(int i= 1; i <= a.n ; i++){
        // Neu da co chu trinh thi khong can kiem tra.
        if(mark[i] == 0 && !cycle)
            breath_first_search(&a,i,mark,&cycle);
    }
    // Ket Qua.
    if(cycle) printf("YES");
    else printf("NO");
 
}