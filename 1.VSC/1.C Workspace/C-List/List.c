#include<stddef.h>
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
typedef struct node* List;

List makenullList(List *L){
    (*L) =(List)malloc(sizeof(List));
    (*L)->next = NULL;
}

void append(int x,List *L){             //con tro bac 2
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
        append(x,&A);
    }
    return A;
}

void printList(List L){
    struct node* P=L;
    while(P->next!=NULL){
        printf("%d ",P->next->data);
        P=P->next;
    }
}
void Menu(List *L){
    while(1==1){
    printf("=============MENU============");
    printf("\n1. Nhap du lieu");
    printf("\n2. In toan bo");    
    printf("\n3. Ket thuc\n");
    printf("=============================\n");
    int t;
    printf("Nhap lua chon:");
    scanf("%d",&t);
    if(t==1){
        printf("Nhap X:");
        int x;
        scanf("%d",&x);
        append(x,L);
        system("cls");
    }
    else if(t==2){
        printf("===========KET==QUA=========");
        printf("Danh sach nay la:");
        printList(*L);
        break;
    }
    else break; 
    }
}

int main(){
    List L;
    makenullList(&L);
    L=readList(&L);
    printList(L);
    return 0;
}

