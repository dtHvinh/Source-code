#include <stdio.h>
#include "StackByArray.c"
#include "D:\Code\1.VSC\1.C Workspace\C-Graph\C-Graph-Edge.c"


int main(){
    Stack a;
    makenullStack(&a);
    Graph g;
    init_Graph(&g,10);
    add_edge(&g,2,3);
    add_edge(&g,2,5);
    add_edge(&g,2,7);
    add_edge(&g,2,1);
    List n;
    makenullList(&n);
    n = neighbors(&g,2);
    printList(n);

}