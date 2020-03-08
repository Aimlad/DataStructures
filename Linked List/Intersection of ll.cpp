// Intersection of ll

int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    int n=0,m=0;
    struct Node * cpy1=head1,*cpy2=head2;

    while(cpy1!=NULL){
        cpy1=cpy1->next;
        n++;
    }

    while(cpy2!=NULL){
        cpy2=cpy2->next;
        m++;
    }
    cpy1=head1;
    cpy2=head2;
    if(n>=m){
        while(n!=m){
            cpy1=cpy1->next;
            n--;
        }
    }
    else{
        while(n!=m){
            cpy2=cpy2->next;
            m--;
        }
    }
    while(cpy1!=NULL && cpy2!=NULL && cpy1!=cpy2){
        cpy1=cpy1->next;
        cpy2=cpy2->next;
    }
    if(cpy1!=NULL && cpy2!=NULL && cpy1==cpy2){
        return cpy1->data;
    }
    return -1;
}
