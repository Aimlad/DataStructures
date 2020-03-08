//Rotate ll

Node* rotate(Node* head, int k) {
    // Your code here
    struct Node * temp= head;

    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=head;
    struct Node *end=head;

    while(k--){
        end=head;
        head=head->next;
    }

    end->next=NULL;
    return head;

}
