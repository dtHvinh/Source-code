#include<stdio.h>
#define size 30

typedef struct{
	int do_dai;
	int dau,cuoi;
}canh;


void read_file(char file_name[], canh a[], int *n){
	int i,j,t;
	float temp;
	FILE *f;
	f = fopen(file_name, "r");
	if(f == NULL){
		printf("Mo file co loi!!!");
		return;
	}
	
	fscanf(f, "%d", n);
	
	int k = 0;
	for(i = 0; i <*n; i++){
		for(j = i; j <*n; j++){
			if(i == j) for(t = 0; t <= j; t++) fscanf(f,"%f",&temp);
			else{
				fscanf(f,"%f", &a[k].do_dai);
				a[k].dau = i;
				a[k].cuoi = j;
				k++;
			}
		}
	}
}

void swap(canh *a, canh *b){
	canh temp = *a;
	*a = *b;
	*b = temp;
}

void bubble_sort(canh a[], int m){
	int i, j;
	for(i = 0; i < m-1; i++)
		for(j =m -1; j > i; j++)
			if(a[j].do_dai < a[j-1].do_dai)
				swap(&a[j], &a[j-1]);
}

void in_ds_canh(canh a[], int m, int la_PA){
	int i;
	float tong = 0.0;
	for(i = 0; i < m; i++){
		printf("%3d %c%c=%8.2f\n", i+1, a[i].dau+65, a[i].cuoi+65, a[i].do_dai);
		if(la_PA)
			tong+= a[i].do_dai;
	}
	if(la_PA)
		printf("Tong do dai cac canh = %8.2f\n", tong);
}

int dinh_cap3(canh PA[], int k, canh moi){
	int i,dem;
	i = 0;
	dem = 1;
	while(i < k && dem < 3) {
		if(moi.dau == PA[i].dau || moi.cuoi == PA[i].cuoi){
			dem++;
		}
		i++;
	}
	if( dem == 3) return 1;
	
	i = 0;
	dem = 1;
	while( i < k && dem < 3){
		if( moi.cuoi == PA[i].dau || moi.cuoi == PA[i].cuoi)
			dem++;
		i++;
	}
	return dem == 1;
}

void init_forest(int parent[], int n){
	int i;
	for(i = 0; i < n ; i++)
		parent[i] = i;
}

int find_root(int parent[], int u){
	while(u != parent[u])
		u = parent[u];
	return u;
}

int chu_trinh(int r_dau, int r_cuoi){
	return r_dau == r_cuoi;
}

void update_forest(int parent[], int r1, int r2){
	parent[r2] = r1;
}

void greedy(canh ds_canh[], int n, canh PA[]){
	int i,j;
	int parent[n];
	init_forest(parent, n);
	int r_dau, r_cuoi;
	
	j = 0;
	for(i =0; i<n*(n-1)/2 && j <n-1; j++){
		r_dau = find_root(parent, ds_canh[i].dau);
		r_cuoi = find_root(parent, ds_canh[i].cuoi);
		if(!dinh_cap3(PA, j, ds_canh[i]) && !chu_trinh(r_dau, r_cuoi)){
			PA[j] = ds_canh[i];
			j++;
			update_forest(parent, r_dau, r_cuoi);
		}
	}
	
	for(; i<n*(n-1)/2; i++){
		r_dau  = find_root(parent, ds_canh[i].dau);
		r_cuoi = find_root(parent, ds_canh[i].cuoi);
		if((!dinh_cap3(PA, n-1, ds_canh[i])) && (chu_trinh(r_dau, r_cuoi))){
			PA[n-1] = ds_canh[i];
			break;
		}
	}
}



int main(){
	canh ds_canh[size];
	int n;
	read_file("TSP.txt",ds_canh,&n);
	printf("Danh sach cac canh cua do thi\n");
	in_ds_canh(ds_canh, n*(n-1)/2, 0);
	
	// bubble_sort(ds_canh, n*(n-1)/2);
	// printf("Danh sach cac canh cua do thi da SAP XEP\n");
	// in_ds_canh(ds_canh, n*(n-1)/2, 0);
	// canh PA[n];
	// greedy(ds_canh, n, PA);
	// printf("PHUONG AN\n");
	
	// in_ds_canh(PA,n,1);
	// return 0;
}
