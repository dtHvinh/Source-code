#include "D:\Code\1.VSC\1.C Workspace\Ex\List.c"
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

// Các lân cận của đỉnh x;
// void neighbors(Graph *pG,int x){
//     for(int i = 0 ; i < pG->m ; i++){
//         int c = pG->E[i].u ;
//         int e = pG->E[i].v;
//         if(c == x){
//             printf("%d ",e);
//             continue;
//         }  
//         if(e == x){
//             printf("%d ",c);
//             continue;
//         }
//     }
// }

List neighbors(Graph *pG , int x){
    List g;
    makenullList(&g);
    for(int i = 0 ; i < pG->m ; i++){
        int l = pG->E[i].u;
        int r = pG->E[i].v;
        if( l == x ) insertList(r , endList(g) , &g);
        if( r == x ) insertList(l , endList(g) , &g);
    }
    return g;
}

