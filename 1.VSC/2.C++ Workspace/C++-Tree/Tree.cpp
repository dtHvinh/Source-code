#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct node{
    int val;
    struct node* left;
    struct node* right;
};

typedef node* TreeNode;

bool emptyTree(TreeNode root){
    return !root; 
}

void makenullTree(TreeNode &root){
    root = NULL;
}

void insertNode(int x,TreeNode &root){
    if(!root){
        root = new node;
        root->val = x;
        root->left  = NULL;
        root->right = NULL;
    }
    else{
        if(x > root ->val) insertNode(x,root->right);
        else insertNode(x,root->left);
    }
}




int main(){
    TreeNode root;
    vector<int>path;
    makenullTree(root);
    insertNode(3,root);
    insertNode(2,root);
    insertNode(4,root);
    insertNode(7,root);
    insertNode(1,root);
}


