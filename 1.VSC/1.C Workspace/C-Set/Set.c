#include<stddef.h>
#include<stdio.h>
#include<stdlib.h>
#define B 100
struct node{
    int data;
    struct node* next;
};

typedef struct node* Dictionary[B]; 

int isEmpty(Dictionary a){
    for(int i = 0 ; i<B ; i++){
        if(a[i]!=NULL) return 0;
    }
    return 1;
}

void makenullDictionary(Dictionary *a){
    for(int i = 0 ; i < B ; i++){
        (*a)[i]= NULL;
    }
}

int H(int x){
    return x%B;
}


int main(){
    Dictionary a;
    makenullDictionary(&a);
    printf("%d",H(3));
    return 0;
}