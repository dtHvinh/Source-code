#include<stdio.h>
#include <stdio.h>
#define MAX_Length 20

typedef struct 
{
    /* data */
    int u, v; // u = dinh 1, v = dinh 2
}edge;

typedef struct 
{
    /* data */
    int n, m; // n = so dinh, m = so canh
    edge data[MAX_Length]; // e = tap hop cac canh
}graph;

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

void initGraph(graph *G, int n){
    G->n = n;
    G->m = 0;
}

void addEdge(graph *G, int u, int v){
    if( u == v) return;
    G->data[G->m].u = u;
    G->data[G->m].v = v;
    G->m++;
} 
int adjacent(graph *G, int u, int v){
    int i;
    for(i = 0; i<=G->m; i++){
        if (G->data[i].u == u && G->data[i].v == v)
        {
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


#define MAX_ELEMENTS 100
typedef struct {
	int data [MAX_ELEMENTS];
	int size;
}Stack;
void make_null_stack(Stack *S){
	S->size=0;
}
void push(Stack *S, int x){
	S->data[S->size] = x;
	S->size++;
}
int top (Stack *S){
	return S->data[S->size-1];
}
void pop(Stack *S){
	 S->size--;
}
int empty(Stack *S){
	return S->size == 0;
}
int num[100];
int min_num[100];
int on_stack[100];
int k = 1;
Stack S;

int min(int a,int b){
	return a < b ? a : b;
}

void strong_connect(graph* G, int x) {
	num[x] = min_num[x] = k; k++;
	push(&S, x);
	on_stack[x] = 1;
	list list = neighbors(G, x);
	
	int j;
	for (j = 0; j < list.size; j++) {
		int y = elementAt(&list, j);
		if (num[y] < 0) {
			strong_connect(G, y);
			min_num[x] = min(min_num[x], min_num[y]);
		} else if (on_stack[y])
			min_num[x] = min(min_num[x], num[y]);
	}
		
	printf("min_num[%d] = %d\n", x, min_num[x]);
	if (num[x] == min_num[x]) {
		printf("%d la dinh khop.\n", x);
		int w;
		do {
			w = top(&S);
			pop(&S);
			on_stack[w] = 0;
		} while (w != x);
	}
}
	
int main(){
	graph a;
	freopen("dothi.txt","r",stdin);
	int n,m;
	scanf("%d%d",&n,&m);
	initGraph(&a,n);
	while(m-->=1){
		int u,v;
		scanf("%d%d",&u,&v);
		addEdge(&a,u,v);
	}
	
	int v;
	for (v = 1; v <= n; v++) {
		num[v] = -1;
		on_stack[v] = 0;
	}

	
	make_null_stack(&S);
	for (v = 1; v <= n; v++) {
		if (num[v] == -1) strong_connect(&a, v);
	}	
	return 0;	
	
}
