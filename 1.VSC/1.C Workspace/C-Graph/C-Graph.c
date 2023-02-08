#include<stdio.h>
#include"C-Graph-Edge.c"


 





int main(){
    Graph g;
    init_Graph(&g,5);
    add_edge(&g, 2, 3);
    add_edge(&g, 2, 4);
    add_edge(&g, 2, 1);
    add_edge(&g, 2, 5);
    List t = neighbors(&g,2);
    printList(t);
}