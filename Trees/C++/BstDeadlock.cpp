//Check whether BST contains Dead End
//https://practice.geeksforgeeks.org/problems/check-whether-bst-contains-dead-end/1
/*
Given a Binary search Tree that contains positive integer values greater then 0.
 The task is to complete the function isDeadEnd which returns true if the
BST contains a dead end else returns false. Here Dead End means,
we are not able to insert any element after that node.
*/

bool helper(Node *root,int low, int high){
    bool flagL=true, flagR=true;

    if(root->left){
        flagL = helper(root->left, low,root->data-1);
    }
    if(root->right){
        flagR = helper(root->right,root->data+1,high);
    }
    if(root->data == low && root->data == high){
        return false;
    }
    else
        return flagL&&flagR;
}

//True - Insertion possible (i.e No deadlock present)

bool isDeadEnd(Node *root)
{
    //Your code here
    if(root==NULL)
        return false;

    return !helper(root,1,INT_MAX);
}
