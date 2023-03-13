#include<iostream>

struct Node{
    int val;
    Node* next;
};

class List{
    public:
        Node* head;
        Node* tail;
    public:
        List() : head(nullptr), tail(nullptr) {};

        bool isEmpty() { return !head; }   

        void addFirst(int val){
            Node* temp = new Node();
            temp->val  = val;
            temp->next = nullptr;

            if(!head){
                head = temp;
                tail = head;
            }
            else{
                temp->next = head;
                head = temp;
            }
        }

        int front(){
            if( !head ) return -1;
            return head->val;
        }

        void addEnd(int val){
            Node* temp = new Node();
            temp->val  = val;
            temp->next = nullptr;

            if(!head){
                head = temp;
                tail = head;
            }
            else{
                tail->next = temp;
                tail = temp;
            }
        }

        int back(){
            if( !tail) return -1;
            return tail->val;
        }

        void printList() {
            Node* curr = head;
            while (curr != nullptr) {
                std::cout << curr->val << " ";
                curr = curr->next;
            }   
        }

        void delFront(){
            if(!head && !tail){
                std::cout<<"List already empty!"<<std::endl;
                return;
            }
            Node* temp = head->next;
            delete(head);
            head = temp;
        }

        void delBack(){
            if(!head && !tail){
                std::cout<<"List already empty!"<<std::endl;
                return;
            }
            if (head == tail) {
                delete tail;
                head = tail = nullptr;
                return;
            }
            Node* temp = head;
            while (temp->next != tail)
            {
                temp = temp->next;
            }
            delete(tail);
            tail = temp;
            tail->next = nullptr;
        }

};








int main(){
    List a = List();

    a.addEnd(1);
    a.addEnd(2);
    a.addEnd(3);
    a.addEnd(4);
    a.addFirst(7);
    a.addFirst(-1);
    a.addFirst(8);
    a.delBack();
    a.printList();
}



/**
 * Bug record:
 * temp->next = head->next; instead of temp->next = head lead to error.
 * in delete back:
 *  Forgot the head == tail case may lead to infinity loops error.
 *  Forgot the last line "tail->next = nullptr;" lead to infinity loops error.
 */



