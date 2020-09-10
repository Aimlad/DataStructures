#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node * left;
    Node * right;

    Node (int data){
    this->data = data;
    this->left=NULL;
    this->right= NULL;
    }
};


void printInorder(Node * root){
    if(root==NULL)
        return;
    if(root->left!=NULL)
        printInorder(root->left);
    cout<<root->data<<" ";
    if(root->right!=NULL)
        printInorder(root->right);
}

void increment(Node* root, int diff){
    root->data+=diff;
    if(root->left !=NULL)
        increment(root->left,diff);
    else
        if(root->right !=NULL)
            increment(root->right,diff);
}

int convertTree(Node *root){
    if(root==NULL)
        return 0;
    int lv=0,rv=0;
    if(root->left!=NULL)
        lv = convertTree(root->left);
    if(root->right!=NULL)
        rv = convertTree(root->right);
    if(root->left == NULL && root->right==NULL)
        return root->data;

    if(root->data - (lv+rv) == 0)
        return root->data;
    else if(root->data - (lv+rv) < 0){
        root->data = lv+rv;
        return root->data;
    }
    else
        if(root->left)
            increment(root->left,root->data-(lv+rv));
        else
            if(root->right)
                increment(root->right,root->data-(lv+rv));
        return root->data;
}


int main()
{
    Node *root = new Node(50);
    root->left = new Node(7);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(5);
    root->right->left = new Node(1);
    root->right->right = new Node(30);

    cout << "\nInorder traversal before conversion: " << endl;
    printInorder(root);

    convertTree(root);

    cout << "\nInorder traversal after conversion: " << endl;
    printInorder(root);
    return 0;
}
