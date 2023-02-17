#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

struct node{
    int val;
    node* left;
    node* right;
};

typedef struct node* TreeNode;

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

int maxDepth(TreeNode* root) {
    stack<pair<TreeNode*, int>> st;

    int depth = 0;
    if (!root) return 0;

    st.push(make_pair(root, depth));
    while (!st.empty()) {
        TreeNode* temp = st.top().first;
        depth = st.top().second;
        st.pop();
        if (temp->left) {
            st.push(make_pair(temp->left, depth + 1));
        }
        if (temp->right) {
            st.push(make_pair(temp->right, depth + 1));
        }
    }
    return depth + 1;
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
    cout<<maxDepth(root);
}
