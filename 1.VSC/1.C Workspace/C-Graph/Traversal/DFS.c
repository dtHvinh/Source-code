#include<stdio.h>
#include"D:\Code\Main\Source-Code\1.VSC\1.C Workspace\C-Graph\C-Graph-List.c"
#include"D:\Code\Main\Source-Code\1.VSC\1.C Workspace\C-Stack\Stack.c"

void DFS(graph a, int x){
    int mark[a.n+1];
    for(int i = 1; i <= a.n; i++) mark[i] = 0;

    Stack st;
    makenullStack(&st);

    push(&st, x);

    while (!emptyStack(&st)){
        int y = top(&st);pop(&st);

        if(mark[y] == 1) continue;

        printf("%d ", y);
        mark[y] = 1;

        List list = neighbors(&a, y);
        for(int i = 0 ; i < length(list); i++){
            int z = elementAt(list, i);
            if(mark[z] == 0){
                push(&st, z);
            }
        }
    }
}

int main(){
    graph a;
    init_graph(&a,5);
    add_edge(&a, 1, 2, 2);
    add_edge(&a, 1, 3, 2);
    add_edge(&a, 1, 4, 2);
    add_edge(&a, 1, 5, 2);
    
    DFS(a, 1);
}
