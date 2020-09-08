// Merge K number of sorted linked list

Node * mergeKLists(Node *arr[], int N)
{
       // Your code here
    Node * res=NULL;
    priority_queue<int, vector<int>, greater<int> > pq;
    int i=0;
    while(i<N){
        Node *temp=arr[i];
        if(temp==NULL){
            i++;
            continue;
        }
        while(temp!=NULL){
            pq.push(temp->data);
            temp=temp->next;
        }
        i++;
    }
    Node *last=NULL;
    while(!pq.empty()){
        int data=pq.top();
        pq.pop();
        Node * newNode = new Node(data);
        newNode->next=NULL;
        if(res==NULL){
            res=newNode;
            last=newNode;
        }
        else{
            last->next=newNode;
            last=newNode;
        }
    }
    return res;
}
