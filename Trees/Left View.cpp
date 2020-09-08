//Left View


//Using Level Order Traversal
void leftView(Node *root)
{
   // Your code here
    if(root==NULL)
        return;

    queue<Node *> q;

    q.push(root);
    while(true){
        int size=q.size();
        if(size==0)
            break;
        cout<<q.front()->data<<" ";
        while(size>0){
            Node * temp=q.front();
            q.pop();

            if(temp->left!=NULL)
                q.push(temp->left);
            if(temp->right!=NULL)
                q.push(temp->right);

            size--;
        }
    }
}


//Using Recursion and no queue

void helper(Node *root, int &max_level, int level){
    if(root==NULL)
        return;

    if(level>max_level){
        cout<<root->data<<" ";
        max_level=level;
    }

    helper(root->left,max_level,level+1);
    helper(root->right,max_level,level+1);
}
void leftView(Node *root)
{
   // Your code here
    if(root==NULL)
        return;
    int max_level=-1, level=0;
    helper(root,max_level,level);
}
