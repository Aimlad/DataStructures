
//https://www.geeksforgeeks.org/construct-bst-from-given-preorder-traversa/
//Construct BST from given preorder traversal
/*
Given preorder traversal of a binary search tree, construct the BST.

For example, if the given traversal is {10, 5, 1, 7, 40, 50}, then the output should be root of following tree.

     10
   /   \
  5     40
 /  \      \
1    7      50

* Solution
* Use the node value in range of min-max approach
*/

int index=0;
Node* create(vector<int> pre,int min,int max){
    if(index>=pre.size())
        return NULL;
    if(pre[index] >min && pre[index] <max){
        Node* node = new Node(pre[index]);
        index++;
        node->left=create(pre,min,node->data);
        node->right=create(pre,node->data,max);
        return node;
    }
    return NULL;
}

Node * Pre2BST(vector<int> pre){
    if(pre.size()==0)
        return NULL;
    create(pre,INT_MIN,INT_MAX);
}
