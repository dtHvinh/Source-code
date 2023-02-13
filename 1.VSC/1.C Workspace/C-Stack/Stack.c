#include<stdlib.h>

struct nodee{
    int val;
    struct nodee* next;
};

typedef struct nodee* Stack;

void makenullStack(Stack *a){
    (*a)=(Stack)malloc(sizeof(Stack));
    (*a)->next = NULL;
}

int emptyStack(Stack *a){
    Stack pos = *a;
    return pos->next == NULL;
}

void push(Stack *a, int x){
    Stack pos = *a;
    while (pos->next != NULL)
    {
        pos = pos->next;
    }
    Stack temp = (Stack)malloc(sizeof(Stack));
    temp->val = x;
    temp->next = pos->next;
    pos->next = temp;
}

int top(Stack *a){
    Stack pos = *a;
    while (pos->next != NULL)
    {
        pos = pos->next;
    }
    return pos->val;
}

void pop(Stack *a){
    struct nodee* pos = *a;
    while (pos->next->next != NULL)
    {
        pos = pos->next;
    }
    
    free(pos->next);
    pos->next = NULL;
}

