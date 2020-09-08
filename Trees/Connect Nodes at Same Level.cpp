//Connect Nodes at Same Level
//Complete the function connect() that takes node as parameter
//and connects the nodes at same level. The printing is done by the driver code.
void innorder(Node *root){
    if(root==NULL)
        return;
    if(root->left!=NULL)
        innorder(root->left);
    cout<<root->data<<" ";
    if(root->right!=NULL)
        innorder(root->right);
}

void levelorder(Node* root){

    queue<Node *> q;
    q.push(root);
    while(true){
        Node * n;
        int size=q.size();
        if(size==0)
            break;
        while(size>0){
            n=q.front();
            q.pop();
            if(q.empty())
                n->nextRight=NULL;
            else
                n->nextRight=q.front();
            //cout<<n->data;
            if(n->left!=NULL)
                q.push(n->left);
            if(n->right!=NULL)
                q.push(n->right);
            size--;
        }
        n->nextRight=NULL;
    }
}

void connect(Node *p)
{
   // Your Code Here
    if(p==NULL)
        return;
    levelorder(p);

}
