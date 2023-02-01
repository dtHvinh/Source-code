#include<stdio.h>
typedef int keytype;

struct node{
    keytype key;
    int height;
    struct node *left,*right;
};

typedef struct node* tree;

void printNLR(tree root){
    if(root!=NULL){
        printf("(%d - %d); ",root->key,root->height);
        printNLR(root->left);
        printNLR(root->right);
    }
}

int main(){
    tree a;
    a->key = 10;
    a->height = 1;
    a->left = NULL;
    a->right = NULL;
   printf("%d",a->height);
}
