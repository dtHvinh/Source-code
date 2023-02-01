#include<stddef.h>
#include<stdlib.h>
#include<stdio.h>

typedef struct{
    int A[100][100];
    int n,m;
}Graph;

void init_Graph(Graph *pG,int n){
    pG->n = n;
    pG->m = 0;
}

void add_edge(Graph *pG,int x,int y){
    pG->A[x][y]++;
    pG->A[y][x]++;
    pG->m++;
}


int deg(Graph *pG,int x){
    int c = 0;
    for(int i = 1; i <= pG->n ; i++){
        if(pG->A[i][x] >0) c++;
    }
    return c;
}

int maxD(Graph *pG){
    int res = 0;
    for(int i = 1; i <= pG->n ; i++){
        if(deg(pG,i) > res%10){
            res = i * 10 + deg(pG,i);
        }
    }
    return res;
}

int main(){
    Graph a;
    int n , m;
    scanf("%d%d",&n,&m);
    init_Graph(&a,n);
    
    while(m--){
        int u , v;
        scanf("%d%d",&u,&v);
        add_edge(&a,u,v);
    }
    int k = maxD(&a);
    printf("%d %d",k/10,k%10);
}


