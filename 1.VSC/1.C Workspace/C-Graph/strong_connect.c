#include<stdio.h>
#include"C-Graph-List.c"
#include"D:\Code\Main\Source-Code\1.VSC\1.C Workspace\C-Stack\Stack.c"


Stack st;
int on_stack[100];
int num[100];
int min_num[100];
int k = 1;

int min(int a, int b){
    return a > b ? b : a;
}

void strong_connect(graph *a, int x){
    num[x] = min_num[x] = k++;
    push(&st,x);
    on_stack[x] = 1;

    List List = neighbors(a,x);
    for(int i = 0 ; i < length(List) ; i++){
        int y = elementAt(List, i);
        if(num[y] < 0){
            strong_connect(a, y);
        }
        else if(on_stack[y]){
            min_num[x] = min(min_num[x], min_num[y]);
        }
    }
    printf("min_num[%d] = %d\n", x, min_num[x]);

    int Dem = 0;
    if(num[x] == min_num[x]){
        printf("%d la dinh khop.\n", x);
        int w;
        do {
            w = top(&st);
            pop(&st);
            on_stack[w] = 0;
            Dem ++;
        } while (w != x);
    } 

    if(Dem == a->n) printf("LIEN THONG MANH!!!!");
}

int main(){
    graph a;
    // Nhap so luong dinh va cung
    int m,n;
    freopen("dothi.txt","r",stdin);
    scanf("%d%d",&n,&m);
    // Tao graph v
    init_graph(&a,n);
    while (m-->=1)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        add_edge(&a,u,v);
    }
    

    int v;
    for (v = 1; v <= n; v++) {
        num[v] = -1;
        on_stack[v] = 0;
    }
    k = 1;
    makenullStack(&st);
    for (v = 1; v <= n; v++) {
        if (num[v] == -1)
            strong_connect(&a, v);
    }

}



