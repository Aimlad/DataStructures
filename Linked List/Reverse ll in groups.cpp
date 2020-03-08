//Reverse LL in groups

struct node *reverse (struct node *head, int k)
{
    // Complete this method
    struct node * prev=NULL,*cur=head,*nxt=NULL;
    int count=0;
    while(cur!=NULL && count<k){
        nxt=cur->next;
        cur->next=prev;
        prev=cur;
        cur=nxt;
        count++;
    }

    if(nxt!=NULL){
        head->next=reverse(nxt,k);
    }

    return prev;

}
