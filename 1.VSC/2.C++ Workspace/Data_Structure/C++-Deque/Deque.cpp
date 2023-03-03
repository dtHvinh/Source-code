#include<iostream>
#include<string>

template<typename T>
struct node{
    T val;
    node<T>* next;
};

template<typename T>

class Deque{
    private:
        node<T>* head;
        int size;
    public:
        /// @brief Constructor
        Deque() : head(nullptr), size(0){}; 

        /// @brief Check if Deque is Empty.
        /// @return "1" True / "0" False.
        bool empty(){
            return !head;
        }

        /// @brief Delete the last element in Deque
        void pop_back(){
            /// if Deque only have 1 element
            if (!head){
                std::cout<<"Unable to pop out"; return;
            }
            /// if Deque have 2 elements
            if (!head->next) {
                delete head;
                head = nullptr;
                return;
            }
            /// reach the end of Deque 
            node<T>* pos = head;
            while (pos->next) pos = pos->next;
            delete pos->next;
            pos->next = nullptr;
            size--;
        }

        /// @brief Add element to the end of the Deque.
        /// @param _val Value which will be added to Deque.
        void push_back(T _val){
            node<T>* new_node = new node<T>{_val, nullptr};
            /// add head if head is empty
            if(!head){
                head = new_node;
            }
        
            else{
                node<T>* pos = head;
                while (pos->next) pos = pos->next;
                pos->next = new_node;
            }
            size++;
        }

        /// @brief Delete the very first element.
        void pop_front() {
            if (!head) {
                std::cout << "Unable to pop out. Deque is empty." << std::endl;
                return;
            }
            /// @note if you directly delete head node you will lost the rest the elements in the list.
            node<T>* temp = head;
            head = head->next;
            delete temp;
            
            size--;
        }

        /// @brief Add 1 element to the very first of the Deque.
        /// @param _val Value which will added to the Deque.
        void push_front(T _val){
            node<T>* new_node = new node<T>{_val, nullptr};
            if(!head) head = new_node;
            else{
                new_node->next = head;
                head = new_node;
            }
            size++;
        }

        /// @brief Display all elements in an Deque
        void print(){
            if(head) std::cout<<head->val;
            node<T>* pos = head;
            while(pos->next){
                std::cout<<"-->"<<pos->next->val;
                pos = pos->next;
            }
        }

        int sizee(){
            return this->size;
        }

};




int main(){
    Deque<int> a = Deque<int>();
    a.push_back(2);
    a.push_back(4);
    a.push_back(7);
    a.push_back(8);
    a.push_front(1);
    std::cout<<a.sizee();
}
