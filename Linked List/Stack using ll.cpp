//Stack using ll

void MyStack ::push(int x) {
    // Your Code
    StackNode * newnode= new StackNode(x);
    newnode->next=NULL;
    if(top==NULL){
        top=newnode;
    }
    else{
        newnode->next=top;
        top=newnode;
    }

}

/* The method pop which return the element
  poped out of the stack*/
int MyStack ::pop() {
    // Your Code
    if(top==NULL)
        return -1;

    int n;
    n=top->data;
    top=top->next;
    return n;
}
