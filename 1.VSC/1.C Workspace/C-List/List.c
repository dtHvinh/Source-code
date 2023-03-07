#include<stddef.h>
#include<stdlib.h>
struct nodee{
    int data;
    struct nodee* next;
};
typedef struct nodee* List;
typedef List Pos;

List makenullList(List *L){
    (*L) =(List)malloc(sizeof(List));
    (*L)->next = NULL;
}

void insertList(int x,List *L){             //con tro bac 2
    List P = *L;
    while(P->next!=NULL){
        P=P->next;
    }
    List A;
    makenullList(&A);
    A->data = x;
    A->next = P->next;
    P->next = A;
}

Pos endList(List L){
    Pos pos;
    while(pos->next != NULL){
        pos = pos->next;
    }
    return pos;
}

void deleteList(List *L){
    Pos p = *L;
    while(p->next->next != NULL){
        p = p->next;
    }
    free(p->next);
    p->next = NULL;
}

int elementAt(List L,int x){
    List pos = L;
    if(x ==0) return pos->next->data;

    while (x-->=0)
    {
        pos = pos->next;
    }
    return pos->data;
    
}

int length(List L){
    List pos = L;
    int c = 0;
    while (pos->next != NULL)
    {
        pos = pos->next;
        c++;
    }
    return c;
}





