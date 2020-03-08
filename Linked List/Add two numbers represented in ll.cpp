// Add two numbers represented in ll 

Node* addTwoLists(Node* first, Node* second) {
    // Code here
    int n=0,m=0,carry=0;
    struct Node *cpy1=first, *cpy2=second;
    struct Node* temp;

    //-----To calculate length-----
    while(cpy1!=NULL){
        cpy1=cpy1->next;
        n++;
    }
    while(cpy2!=NULL){
        cpy2=cpy2->next;
        m++;
    }
    //------------------------------

    //Swap and keep longer one as first
    if(n<m){
        temp=first;
        first=second;
        second=temp;
    }
    //------------------------------


    cpy1=first; cpy2=second;        //Reset values to head

    //--------Until shorter ll is over---------
    while(cpy2!=NULL){
        cpy1->data=cpy1->data + cpy2->data+carry;
        carry=(cpy1->data)>9?1:0;
        cpy1->data=cpy1->data%10;
        temp=cpy1;
        cpy1=cpy1->next;
        cpy2=cpy2->next;
    }


    if(carry>0 && cpy2==NULL){
        if(cpy1==NULL){     // If first list is over and carry remain
            struct Node* newnode = new Node(carry);
            newnode->next=NULL;
            temp->next=newnode;
        }
        else{
            while(cpy1!=NULL && carry>0){   // If 1st is longer than 2nd
                cpy1->data=cpy1->data+carry;
                carry=(cpy1->data)>9?1:0;
                cpy1->data=cpy1->data%10;
                cpy1=cpy1->next;
            }
        }
    }
    return first;
}
