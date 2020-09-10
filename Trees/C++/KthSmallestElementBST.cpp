//k-th smallest element in BST
//https://practice.geeksforgeeks.org/problems/find-k-th-smallest-element-in-bst/1

/*
* Solution :
* 1. Maintain a stack and initially keep traversing root.left until null is reached
* 2. when next is called, pop current element and  push all its right child's left nodes
*/

void pushAll(Node* node,stack <Node*> &s){
    while(node!=NULL){
        s.push(node);
        node=node->left;
    }
}

int KthSmallestElement(Node *root, int K)
{
    //add code here.
    stack <Node*> s;
    if(root==NULL)
        return -1;
    pushAll(root,s);
    int res;
    while(K && !s.empty()){
        Node* tmp=s.top();
        res=tmp->data;
        s.pop();
        pushAll(tmp->right,s);
        K--;
    }

    if(K>0)
        return -1;
    return res;

}
