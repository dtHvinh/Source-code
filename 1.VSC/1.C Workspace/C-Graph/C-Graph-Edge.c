#include "D:\Code\Main\Coding-File\1.VSC\1.C Workspace\C-List\List.c"
#define Max_M 100
/*
Cài đặt theo phương thức các cung 0,1,.. sẽ chứa các cặp đỉnh u,v ví dụ như [1,2];
Ban đầu cho m = 0 (Cung) trong hàm init rồi sau đó tăng m(Cung) dần trong hàm add_edge; 
*/

typedef struct{
    int u,v;
}edge;

typedef struct {
    edge E[Max_M];
    int n,m;            
}Graph;

//Khởi tạo
void init_Graph(Graph *pG,int x){
    pG->n = x; 
    pG->m = 0;
}

//Thêm cung
void add_edge(Graph *pG,int u, int v){
    pG->E[pG->m].u = u;
    pG->E[pG->m].v = v;
    pG->m++;
}

//Bậc của đỉnh
int deg(Graph *pG,int x){
    int c = 0;
    for(int i = 0 ; i < pG->m ; i++){
        if(pG->E[i].u == x || pG->E[i].v == x) c++;         
    }
    return c;
}

List neighbors(Graph *pG , int x){
    List g;
    makenullList(&g);
    for(int i = 0 ; i < pG->m ; i++){
        int l = pG->E[i].u;
        int r = pG->E[i].v;
        if( l == x ) insertList(r, &g);
        if( r == x ) insertList(l, &g);
    }
    return g;
}


