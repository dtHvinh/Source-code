#include<iostream>

using namespace std;

struct node{
    int val;
    node* next;
};

typedef node* List;

void makenull(List &List){
    List = nullptr;
}

bool isEmpty(List List){
    return !List;
}

void insertList(List &List, int x){
    node* new_node = new node();
    new_node->val  = x;
    new_node->next = nullptr;

    if(!List){
        List = new_node;
    }
    else{
        node* cur = List;
        while (cur->next)
        {
            cur = cur->next;
        }
        cur->next = new_node;
    }
}

void printList(List List){
    cout<<List->val<<" ";
    while (List->next)
    {
        cout<<List->next->val<<" ";
        List = List->next;
    }
}

int main(){
    List a;
    makenull(a);
    insertList(a,1);
    insertList(a,2);
    insertList(a,3);
    List b;
    makenull(b);
    insertList(b,4);
    insertList(b,5);
    insertList(b,6);
    List c = new node();
    c->next = nullptr;
    c->val = 1;
    c->next = b;
    c->next->next = a->next;
    printList(c);
}

