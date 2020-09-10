//Level Order spiral traversal


void printSpiral(Node *root)
{
    //Your code here
    if(root==NULL)
        return;
    deque <Node *> dq;
    dq.push_back(root);
    bool LR=false;

    while(true){
        int size=dq.size();
        if(size==0)
            return;
        while(size>0){
            Node * n;

            if(LR){
                n=dq.front();
                dq.pop_front();
                cout<<n->data<<" ";
                if(n->left!=NULL)
                    dq.push_back(n->left);
                if(n->right!=NULL)
                    dq.push_back(n->right);
            }
            if(!LR){
                n=dq.back();
                dq.pop_back();
                cout<<n->data<<" ";
                if(n->right!=NULL)
                    dq.push_front(n->right);
                if(n->left!=NULL)
                    dq.push_front(n->left);
            }
            size--;
        }
        LR=!LR;
    }
}
