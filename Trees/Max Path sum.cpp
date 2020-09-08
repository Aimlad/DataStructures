//Max Path sum from leaf to leaf
//Final result is only updated if there is some value obtained from both
// left and right subtree

int maxPathSumUtil(Node *root, int &res)
{
    if(root==NULL)
        return 0;
    //If both left and right null then simply return root
    if(root->left ==NULL && root->right==NULL)
        return root->data;

    int ls=0,rs=0;
    ls=maxPathSumUtil(root->left,res);
    rs=maxPathSumUtil(root->right, res);

    //Only if both exist
    if(root->left !=NULL && root->right!=NULL){
      //Update the result to maximum possible value
        res=max(res,ls+rs+root->data);

        //return max of (left , right)subtree + root->Data
        return max(ls,rs)+root->data;
    }

    //if one of them is not NULL, return that particular value only;
    return (root->left!=NULL)?ls+root->data : rs+root->data;
}


int maxPathSum(Node *root) {
    // code here
    int res = INT_MIN;
    maxPathSumUtil(root, res);
    return res;

}
