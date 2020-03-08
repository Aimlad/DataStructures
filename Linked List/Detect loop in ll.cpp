//Detect loop in ll

int detectloop(Node *head) {
    struct Node * sptr=head, *fptr=head;
    if(head==NULL)
        return 0;
    while(fptr->next!=NULL && fptr->next->next!=NULL){
        sptr=sptr->next;
        fptr=fptr->next->next;
        if(sptr==fptr)
            return 1;
        }
    return 0;
}
