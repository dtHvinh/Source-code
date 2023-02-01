#include<stdio.h>

typedef struct 
{
    int arr[100];
    int n;
}Stack;

void makenullStack(Stack* a){
    a->n = 0;
}

int size(Stack a){
    return a.n;
}

void push(Stack *a, int x){
    a->n++;
    a->arr[a->n] = x;
}

int empty(Stack a){
    return a.n == 0;
}

int top(Stack a){
    return a.arr[a.n];
}

void pop(Stack *a){
    a->n--;
}



