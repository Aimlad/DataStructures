bool hasPath(Node *root,vector<int> &arr,int target)
{
    if(root==NULL)
        return false;

    arr.push_back(root->data);

    if(root->data == target)
        return true;

    if(hasPath(root->left,arr,target) || hasPath(root->right,arr,target))
        return true;

    arr.pop_back();
    return false;
}
