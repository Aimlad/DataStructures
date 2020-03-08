//Check if ll is pallindrome

Node* reverse(struct Node * head){
    struct Node* prev=NULL, *cur=head, *temp;

    while(cur!=NULL){
        temp=cur->next;
        cur->next=prev;
        prev=cur;
        cur=temp;
    }
    head=prev;
    return head;
}

bool isPalindrome(Node *head)
{
    //Your code here
    struct Node *slowptr=head, *fastptr=head;
    struct Node *temp,*copy=head,*midnode=NULL;
    bool result;

    //-----Finding the middle element------
    while(fastptr!=NULL && fastptr->next!=NULL){
        temp=slowptr;
        slowptr=slowptr->next;
        fastptr=fastptr->next->next;
    }
    //--------------------------------------

    //---------fastptr=NULL when even, so below case for odd-------

    if(fastptr!=NULL){
        midnode=slowptr;
        slowptr=slowptr->next;
    }

    //-------------------------------------------------------------

    //Reverse Second half and start comparison
    temp->next=reverse(slowptr);
    temp=temp->next;



    while(temp!=NULL){
        if(copy->data!=temp->data){
            return false;
        }
        temp=temp->next;
        copy=copy->next;
    }

    return true;
}
