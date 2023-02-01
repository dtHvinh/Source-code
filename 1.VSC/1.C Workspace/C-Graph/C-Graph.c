#include<stdio.h>
#include"C-Graph-Edge.c"


 





int main(){
    Graph e;
    init_Graph(&e,3);
    add_edge(&e,1,2);
    add_edge(&e,1,3);
    add_edge(&e,3,1);
    neighbors(&e,1);
}