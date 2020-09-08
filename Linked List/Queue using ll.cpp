//Queue using ll
//GeeksforGeeks

void MyQueue:: push(int x)
{
        // Your Code
        QueueNode * newnode = new QueueNode(x);
        newnode->next=NULL;
        if(front==NULL && rear==NULL){
            front=newnode;
            rear=newnode;
        }
        else{
        rear->next=newnode;
        rear=newnode;
        }
}

/*The method pop which return the element
  poped out of the queue*/
int MyQueue :: pop()
{
        // // Your Code
        if(front==NULL)
            return -1;
        int n;
        n=front->data;
        if(front->next!=NULL)
            front=front->next;
        else if(front->next==NULL && front==rear){
            front=NULL;
            rear=NULL;
        }
        return n;

}
