// https://practice.geeksforgeeks.org/problems/level-order-traversal/1



int height(Node* node){
    if(node == NULL)
        return 0;

    int lheight = height(node->left);
    int rheight = height(node->right);

    if(lheight > rheight)
        return (lheight+1);
    return rheight+1;
}
void printLevel(Node* root, int level,vector<int> &res){
    if(root==NULL)
        return;
    if(level == 1)
        res.push_back(root->data);
    if(root->left!=NULL)
        printLevel(root->left, level-1,res);
    if(root->right!=NULL)
        printLevel(root->right, level-1,res);
}
vector<int> levelOrder(Node* node)
{
  //Your code here
    vector<int> res;
    if(node==NULL)
        return res;
    int h = height(node);
    for(int i=1; i<=h; i++){
        printLevel(node,i,res);
    }
    return res;
}
