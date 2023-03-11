#include <stdio.h>
#include <stdlib.h>

int tsp(int n, int start){

}

int main(){
	freopen("TSP.txt", "r", stdin);
	int n;
	scanf("%d",&n);


	float graph[n+1][n+1];
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			graph[i][j] = 0;
		}
	}


	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			scanf("%f",&graph[i][j]);
		}
	}

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			printf("%.2f ",graph22[i][j]);
		}
		printf("\n");
	}

	
}	