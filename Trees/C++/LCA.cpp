//LCA

//Method 1 : Leetcode

Node* LCA(Node *root, int n1, int n2)
{
   //Your code here
   //If root==NULL, then return null
    if(root==NULL)
        return root;

    // if any of the node is found, then return that node
    if(root->data == n1 || root->data==n2)
        return root;

    //traverse left and right
    Node * left= LCA(root->left, n1, n2);
    Node * right= LCA(root->right, n1, n2);


    // Imagine value is being returned from both left and nextRight
    // that means,n1 and n2 is in either of the subtree(left or right)
    if(left && right)
        return root;

    // If left value is returned, then return left
    if(left!=NULL)
        return left;
    //else return right(even if it is NULL)
    else
        return right;
}
