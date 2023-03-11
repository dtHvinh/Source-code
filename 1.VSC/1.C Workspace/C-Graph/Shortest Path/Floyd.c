#include<stdio.h>

int c;

#define INF 9999999

void floyd(int graph[][c+1]) {
    int path[c+1][c+1];
    int i, j, k;
    
    // Initialize dist matrix with the values from graph matrix
    for (i = 1; i <= c; i++) {
        for (j = 1; j <= c; j++) {
            path[i][j] = graph[i][j];
        }
    }
    
    // Find shortest path for all pairs of vertices
    for (k = 1; k <= c; k++) {
        for (i = 1; i <= c; i++) {
            for (j = 1; j <= c; j++) {
                if (path[i][k] + path[k][j] < path[i][j]) {
                    path[i][j] = path[i][k] + path[k][j];
                }
            }
        }
    }
    
    // Print the shortest path matrix
    for (i = 1; i <= c; i++) {
        for (j = 1; j <= c; j++) {
            printf("%d --> %d = ", i, j);
            if(i == j) printf("0\n");
            else if( path[i][j] == INF) printf("oo\n");
            else printf("%d\n", path[i][j]);
        }
    }
}


int main(){
    freopen("testcase.txt","r",stdin);
    int m;
    scanf("%d%d",&c,&m);
    int graph[c+1][c+1];
    for(int i = 1; i <= c; i++){
        for(int j = 1; j <= c ; j++){
            graph[i][j] = INF;
        }
    }
    while(m-->=1){
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        graph[u][v] = w;
    }

    floyd(graph);
    
}