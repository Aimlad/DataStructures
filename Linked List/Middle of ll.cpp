//Middle of ll

int getMiddle(Node *head)
{
   // Your code here
   struct Node *slowptr=head,*fastptr=head;
   if(head==NULL)
        return -1;
   while(fastptr && fastptr->next){
       slowptr=slowptr->next;
       fastptr=fastptr->next->next;
   }
   return slowptr->data;
}
