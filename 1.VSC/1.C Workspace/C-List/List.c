#include<stddef.h>
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
typedef struct node* List;
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

List readList(){
    List A;
    makenullList(&A);
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        insertList(x,&A);
    }
    return A;
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

    while (x--)
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

void printList(List L){
    struct node* P=L;
    while(P->next!=NULL){
        printf("%d ",P->next->data);
        P=P->next;
    }
}



