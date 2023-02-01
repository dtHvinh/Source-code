#include<stdio.h>
#include <stdlib.h>
struct Node{
    int Element;
    struct Node* Next;
};
typedef struct Node* Position;
typedef Position List;

Position first(List L){
    return L;
}
void insertList(int X, Position P, List *L){
     Position T;
    T=(Position)malloc(sizeof(Position));  
    T->Element=X;  
    T->Next=P->Next;  
    P->Next=T;  
} 
Position endList(List L) {
    Position P = first(L);
    while (P->Next!=NULL)
    P=P->Next;
    return P;
}
void printList(List L){
    Position P=first(L), E=endList(L);
    while (P!=E) {
    printf("%d ", P->Next->Element);
    P=P->Next;
    }
}
void readList(List *L){
    int n, i;
    int X;
    printf("Cho biet so phan tu cua danh sach: ");
    scanf("%d",&n);
    for (i=1; i<=n; i++){
        printf("Nhap phan tu thu %d=",i);
        scanf("%d", &X);
        insertList(X, endList(*L),L);}
}
void makenullList(List *L) {
    (*L) =(struct Node*)malloc(sizeof(struct Node));
    (*L) ->Next = NULL;
}

