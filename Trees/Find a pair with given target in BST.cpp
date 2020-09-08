//Find a pair with given target in BST

bool findpair(Node *root, int key, Node *orig){
    if(root==NULL)
        return false;

    if(root->data == key && root!= orig){
        return true;
    }

    else if(root->data < key)
        return findpair(root->right,key,orig);
    else if(root->data > key)
        return findpair(root->left,key,orig);

    return false;
}
bool inorder(Node *root, int target,Node * orig){

    if(root==NULL)
        return false;

    if(root->data < target){
        return findpair(orig,target-root->data,root)
                || inorder(root->left,target,orig)
                || inorder(root->right,target,orig);
    }
    return inorder(root->left,target,orig)
        || inorder(root->right,target,orig);
}
bool isPairPresent(struct Node *root, int target)
{
//add code here.

    if(root==NULL)
        return false;

    return inorder(root, target,root);

}
