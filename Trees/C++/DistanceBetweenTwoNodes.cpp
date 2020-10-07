//https://practice.geeksforgeeks.org/problems/min-distance-between-two-given-nodes-of-a-binary-tree/1
/*
Solution :

1 : Find LCA of both the given nodes
2 : Find level of both the nodes taking LCA as the root
3 : Sum both the levels

*/

Node* lca(Node* root, int a, int b){
    if(root==NULL)
        return NULL;

    if(root->data == a || root->data==b)
        return root;

    Node* left = lca(root->left,a,b);
    Node* right = lca(root->right,a,b);

    if(left && right)
        return root;

    return left?left:right;


}

int dist(Node* root, int a,int l){
    if(root==NULL)
        return 0;
    if(root->data==a)
        return l;
    int left= dist(root->left,a,l+1);

    if(left != 0)
        return left;
    return dist(root->right,a,l+1);
}
int findDist(Node* root, int a, int b) {
    // Your code here
    if(root == NULL)
        return -1;
    Node* anc = lca(root,a,b);
    if(anc == NULL)
        return -1;
    int res = dist(anc, a,0) + dist(anc, b,0);
    return res;

}
