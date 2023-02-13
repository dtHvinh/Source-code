#include"D:\Code\Main\Coding-File\1.VSC\1.C Workspace\C-Graph\C-Graph-Edge.c"
#include"D:\Code\Main\Coding-File\1.VSC\1.C Workspace\C-Stack\Stack.c"

void BFS(Graph *a){
    Stack st;
    makenullStack(&st);
    printf("BFS: ");

    int mark[20];
    for(int i = 0 ; i < 20 ; i++){
        mark[i] = 0;
    }

    push(&st,1);
    printf("1 ");
    mark[1] = 1;

    while(!emptyStack(&st)){
        int x = top(&st); pop(&st);

        List l = neighbors(a,x);
        for(int i = 0 ; i < length(l) ; i++){
            int y = elementAt(l,i);
			if (mark[y] == 0) { 
				printf("%d ", y);
				mark[y] = 1; 
				push(&st, y); 
			}
        }
    }
}




