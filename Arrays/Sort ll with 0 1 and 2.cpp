//Sort ll with 0 1 and 2


Node* segregate(Node *head) {

    // Add code here
    struct Node * temp=head;
    int zc=0,oc=0,tc=0;
    while(temp!=NULL){
        if(temp->data==0)
            zc++;
        else if(temp->data==1)
            oc++;
        else if(temp->data==2)
            tc++;
        temp=temp->next;
    }
    temp=head;
    while(temp!=NULL){
        if(zc>0){
            temp->data=0;
            zc--;
        }
        else if(oc>0){
            temp->data=1;
            oc--;
        }
        else if(tc>0){
            temp->data=2;
            tc--;
        }
        temp=temp->next;
    }

    return head;

}
