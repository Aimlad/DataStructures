// Check if BST
// Inorder traversal should be sorted in increasing order
// Method 1 : Using Sorting
void helper(Node * root,vector <int> &v){
    if(root==NULL)
        return;
    if(root->left != NULL)
        helper(root->left,v);
    v.push_back(root->data);
    if(root->right!=NULL)
        helper(root->right,v);
}

bool isBST(Node* root) {
    // Your code here
    if(root==NULL || (root->left==NULL && root->right==NULL))
        return true;
    vector <int> v;
    helper(root,v);
    bool flag=true;
    for(int i=0;i<v.size()-1;i++){
        if(v[i]>=v[i+1]){
            flag=false;
            break;
        }
    }

    return flag;
}

//Method 2  : Using BST property and Range technique
int min= INT_MIN;
int max= INT_MAX;
int check(Node * root, int min, int max){
  if(root==NULL)
    return 1;
  if(root->data > min || root->data < max){
    int lv= check(root->left,min,root->data);
    int rv= check(root->right,root->data, max);
    return (lv && rv);
  } else return 0;
}
