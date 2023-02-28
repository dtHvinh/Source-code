#include<stdio.h>
#include"D:\Code\Main\Source-Code\1.VSC\1.C Workspace\C-Graph\C-Graph-List.c"
#include"D:\Code\Main\Source-Code\1.VSC\1.C Workspace\C-Queue\Queue.c"

void BFS(graph a, int x){
    int mark[a.n+1];
    for(int i = 1; i<= a.n ;i++){
        mark[i] = 0;
    }
    
    Queue q;
    makenullQueue(&q);

    printf("%d ", x);
    mark[x] = 1;
    enQueue(&q, x);

    while(!emptyQueue(q)){
        int y = frontValue(q);deQueue(&q);

        List list = neighbors(&a, y);
        for (int i = 0; i < length(list); i++){
            int z = elementAt(list, i);
            if(mark[z] == 1) continue;
            else{
                printf("%d ",z);
                enQueue(&q, z);
                mark[z] = 1;
            }
        } 
    }

}

// In start_vertex roi mark[start_vertex];
// Quang no vao queue
// lay ra
// list neigbor cua dau` queue
// xet tung dua trong queue
// mark roi thi continue;
// khong thi in ra -> mark -> dua no vao lai queue;



int main(){
    graph a;
    init_graph(&a,5);
    add_edge(&a, 1, 2, 2);
    add_edge(&a, 1, 3, 2);
    add_edge(&a, 1, 4, 2);
    add_edge(&a, 1, 5, 2);

    BFS(a, 1);
}


