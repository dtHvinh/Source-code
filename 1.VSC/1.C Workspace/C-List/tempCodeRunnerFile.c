void append(int x,List *L){             //con tro bac 2
    List P = *L;
    while(P->next!=NULL){
        P=P->next;
    }
    List A;
    makenullList(&A);
    A->data = x;
    A->next = P->next;
    P->next = A;
}