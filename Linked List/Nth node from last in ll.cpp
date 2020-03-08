//Nth node from last in ll 

int getNthFromLast(Node *head, int n)
{
       // Your code here
        if(head==NULL)
            return -1;
       struct Node * sptr=head, *fptr=head;
       while(fptr!=NULL && n>0){
           fptr=fptr->next;
           n--;
       }
       while(fptr!=NULL){
           sptr=sptr->next;
           fptr=fptr->next;
       }
        if(fptr==NULL && n>0)
            return -1;
       return sptr->data;
}
