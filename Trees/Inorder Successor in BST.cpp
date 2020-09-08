Node * res=NULL;
void helper(Node * root,Node *x,bool &flag){

    if(root==NULL)
        return;

    helper(root->left,x,flag);
    if(flag==true && root->data > x->data){
        res=root;
        flag=false;
        return;
    }

    if(root == x){
        flag=true;
    }
    helper(root->right,x,flag);
}

Node * inOrderSuccessor(Node *root, Node *x)
{
    //Your code here
    if (root==NULL || (root->left==NULL && root->right==NULL)){
        return NULL;
    }
    bool flag=false;
    res=NULL;
    helper(root,x,flag);
    return res;
}
