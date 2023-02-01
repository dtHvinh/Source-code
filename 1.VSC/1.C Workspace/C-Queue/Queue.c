#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* next;
};
typedef struct node* Queue;

void makenullQueue(Queue *A){
    (*A) = (Queue)malloc(sizeof(Queue));
    (*A) -> next = NULL;
}

int emptyQueue(Queue L) {
    return (L->next==NULL);
}

void enQueue(int x,Queue *A){
    Queue temp;
    makenullQueue(&temp);
    Queue P = *A;
    while(P->next !=NULL){
        P=P->next;
    }
    temp->data = x;
    temp->next = P->next;
    P->next    = temp;
}

void deQueue(Queue *A){
    Queue temp,P=*A;
    temp=P->next; 
    P->next=temp->next; 
    free(temp);
}

void inDau(Queue A){
    Queue P=A;
    printf("%d",P->next->data);
} 

int dem(Queue A){
    Queue P =A;
    int dem=0;
    while(P->next != NULL){
        dem++;
        P=P->next;
    }
    return dem;
}

int main(){
    int n;
    Queue A;
    makenullQueue(&A);
    scanf("%d",&n);
    fflush(stdin);
    for(int i=1;i<=n;i++){
        char c;
        scanf("%c",&c);
        if(c == 'E'){
            int n;
            scanf("%d",&n);
            fflush(stdin);
            enQueue(n,&A);
            printf("%d\n",dem(A));
        }
        else{
            if(emptyQueue(A)){
                printf("-1 ");
                printf("%d",dem(A));
            }
            else{
                inDau(A);
                deQueue(&A);
                printf(" %d",dem(A));
            }
        }
    }
}