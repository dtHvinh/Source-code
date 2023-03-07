#include"D:\Code\Main\Source-Code\1.VSC\1.C Workspace\C-Graph\C-Graph-List.c"
#include"D:\Code\Main\Source-Code\1.VSC\1.C Workspace\C-Stack\Stack.c"
#include<stdio.h>

void DFS(graph *a, int s){
    Stack st;
    makenullStack(&st);
    printf("DFS: ");

    int mark[20];
    for(int i = 0 ; i < 20 ; i++){
        mark[i] = 0;
    }

    push(&st, s);

    while(!emptyStack(&st)){
        int x = top(&st); pop(&st);
        printf("%d ", x);
        mark[x] = 1;

        List l = neighbors(a,x);
        for(int i = 0 ; i < length(l) ; i++){
            int y = elementAt(l,i);
			if (mark[y] == 0) { 
				push(&st, y); 
			}
        }
    }
}


int main(){
    graph a;
    init_graph(&a, 4);
    add_edge(&a, 2, 1, 2);
    add_edge(&a, 1, 3, 2);
    add_edge(&a, 2, 4, 2);
    

    DFS(&a, 1);
}






