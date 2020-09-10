//Check for Balanced Tree

int helper(Node *root, bool &res){
    if(root==NULL)
        return 0;

    if(root->left==NULL && root->right==NULL)
        return 1;
    int ls=0,rs=0;
    ls=helper(root->left,res);
    rs=helper(root->right,res);
    res=res && ((abs(ls-rs)<=1)?true:false);
    if(root->left!=NULL && root->right!=NULL){
        return max(ls,rs)+1;
    }

    return (root->left!=NULL)?ls+1:rs+1;

}

bool isBalanced(Node *root)
{
    //  Your Code here

    bool res=true;
    if(root==NULL)
        return true;
    helper(root,res);
    return res;
}
