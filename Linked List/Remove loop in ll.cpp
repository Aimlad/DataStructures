// Remove Loop in ll

void removeTheLoop(Node *head)
{
     //Your code here
     struct Node * sptr=head, *fptr= head;
     bool flag=false;
     while(fptr->next!=NULL && fptr->next->next!=NULL){
         sptr=sptr->next;
         fptr=fptr->next->next;
         if(sptr==fptr){
             flag=true;break;
         }
     }
     if(flag){
         sptr=head;
         struct Node *temp;
         while(sptr!=fptr){
            sptr=sptr->next;
            temp=fptr;
            fptr=fptr->next;
         }
         if(sptr==fptr)
            temp->next=NULL;
     }
     return;
}
