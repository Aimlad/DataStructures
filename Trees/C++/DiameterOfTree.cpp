//Diameter of Tree

int helper(Node* root, int &res){
    if(root==NULL)
        return 0;
    if(root->left==NULL && root->right==NULL)
        return 1;

    int ls=0,rs=0;
    ls=helper(root->left,res);
    rs=helper(root->right,res);

    res= max(res, ls+rs+1);
    if(root->left!=NULL && root->right!=NULL){
         return max(ls,rs)+1;
    }

    return (root->left!=NULL)? ls+1: rs+1;
}

int diameter(Node* node) {
    // Your code here
    int res=0;
    if(node==NULL)
        return 0;
    helper(node,res);
    return res;
}
