#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* left;
    struct node* right;
};
typedef struct node* Tree;

void makenullTree(Tree *a){
    *a= NULL;
}

void insertNode(int x,Tree *t){                        // them phan tu
	if ((*t) == NULL){
		(*t) = (Tree)malloc(sizeof(Tree));
		(*t)->data =x;
		(*t)->left = NULL;
		(*t)->right = NULL;
	} else{
        if((*t)->data == x) printf("Da Ton Tai");
		else if (x < (*t)->data){
			insertNode(x,&(*t)->left);
		} else if(x > (*t)->data){
			insertNode(x,&(*t)->right);
		}
	}	
}

void NLR(Tree root){                                // Tien tu
    if (root!=NULL){
        printf("%d ",root->data);
        NLR(root->left);
        NLR(root->right);
    }
}

void LRN(Tree root){                                // Hau tu
    if (root!=NULL){
        NLR(root->left);
        NLR(root->right);
        printf("%d ",root->data);
    }
}

void LNR(Tree root){                                // Trung tu
    if (root!=NULL){
        NLR(root->left);
        printf("%d ",root->data);
        NLR(root->right);
    }
}

void dao(Tree a, Tree *b){
    if(a != NULL){
        (*b)->data = a->data;
        (*b)->left = NULL;
        (*b)->right = NULL;
        dao(a->left,&(*b)->right);
        dao(a->right,&(*b)->left);
    }
}
int main(){
    Tree T;
    makenullTree(&T);
    insertNode(27,&T);
    insertNode(12,&T);
    insertNode(40,&T);
    printf("NLR: "); NLR(T);
  

    printf("\n");

}