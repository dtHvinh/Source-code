    List c = new node();
    c->val = a->val;
    c->next = nullptr;
    node* curr = c; // create a pointer to traverse c
    while (curr->next) {
        curr = curr->next;
    }
    curr->next = b; // attach b to the end of c
    printList(c);