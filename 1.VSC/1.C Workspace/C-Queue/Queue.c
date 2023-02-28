#include <stdlib.h>
struct node{
    int data;
    struct node* next;
};
typedef struct node* Queue;

// init_ queue
void makenullQueue(Queue *A){
    (*A) = (Queue)malloc(sizeof(Queue));
    (*A) -> next = NULL;
}


// check if queue is empty
int emptyQueue(Queue L) {
    return (L->next==NULL);
}

// add 1 element to Queue
void enQueue(Queue *A, int x){
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

// pop the first element in a line
void deQueue(Queue *A){
    Queue temp,P=*A;
    temp=P->next; 
    P->next=temp->next; 
    free(temp);
}

// return the value of the very first element
int frontValue(Queue A){
    Queue P=A;
    return P->next->data;
} 



