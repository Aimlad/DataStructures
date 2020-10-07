int height(Node * root, int key,int lvl){

    if(root== NULL)
        return 0;

    if(root->data == key)
        return lvl;

    int left = height(root->left, key, lvl+1);
    if(left != 0)
        return left;

    return height(root->right, key, lvl+1);

}
