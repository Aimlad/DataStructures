//Reverse LL

Node* reverse(Node *head)
{
  // Your code here
  struct Node *temp,*prev=NULL,*cur=head;
  while(cur!=NULL){
      temp=cur->next;
      cur->next=prev;
      prev=cur;
      cur=temp;
  }
  head=prev;
}
