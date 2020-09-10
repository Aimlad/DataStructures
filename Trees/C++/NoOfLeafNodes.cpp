//Number of Leaf Nodes

void helper(Node *root, int &res){

    if(root==NULL)
        return;
    if(root->left==NULL && root->right==NULL)
        res++;
    if(root->left!=NULL)
        helper(root->left,res);
    if(root->right!=NULL)
        helper(root->right,res);
}
int countLeaves(Node* root)
{
  // Your code here
    if(root==NULL)
        return 0;
    int res=0;
    helper(root,res);
    return res;

}
