#include<stdio.h>
#include<stdlib.h>
typedef struct{
    int bac;
    int heso;
}DonThuc;

struct node{
    DonThuc e;
    struct node* next;
};

typedef struct node* DaThuc;

struct node* khoitao(){
    DaThuc A;
    A = (DaThuc)malloc(sizeof(DaThuc));
    A -> next = NULL;
    return A;
}

struct node* Last(DaThuc A){
    DaThuc P = A;
    while(P->next != NULL){
        P=P->next;
    }
    return P;
}

void addend(DonThuc x,DaThuc *A){
    DaThuc temp;
    temp = khoitao();
    DaThuc P=Last(*A);
    temp->e.heso = x.heso;
    temp->e.bac  = x.bac;
    temp->next = P->next;
    P->next = temp;
}

void inDaThuc(DaThuc A){
    DaThuc P = A;
    printf("%dx^%d ",P->next->e.heso,P->next->e.bac);
    P=P->next;
    for(P;P->next != NULL;P=P->next){
        printf("+ %dx^%d",P->next->e.heso,P->next->e.bac);
    }
}

void nhapDaThuc(DaThuc *A){
    *A=khoitao();
    printf("Da thuc co bac: ");
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        DonThuc a;
        scanf("%d",&a.heso);
        a.bac = n-i+1;
        addend(a,A);
    }
}


int main(){
    DaThuc A;
    nhapDaThuc(&A);
    inDaThuc(A);
    return 0;
}