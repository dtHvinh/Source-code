#include<stdio.h>
int main(){
    graph a;
    init_graph(&a, 4);
    add_edge(&a, 2, 1, 2);
    add_edge(&a, 1, 3, 2);
    add_edge(&a, 2, 4, 2);
    List t = neighbors(&a, 2);
    for(int i = 0 ; length(t); i++){
        printf("%d ",elementAt(t, i));
    }
}