//Print left Boundary
//Print leaves
//Print Right Boundary in reverse

void leaves(Node *root){
    if (root == NULL)
        return;

    if(root->left == NULL && root->right==NULL)
        cout<<root->data<<" ";

    leaves(root->left);
    leaves(root->right);
}
void leftB(Node* root){
    if(root == NULL)
        return;

    if(root->left != NULL){
        cout<<root->data<<" ";
        leftB(root->left);
    }
    else if(root->right != NULL){
        cout<<root->data<<" ";
        leftB(root->right);
    }
}

void rightB(Node* root){
    if(root == NULL)
        return;

    if(root->right != NULL){
        rightB(root->right);
        cout<<root->data<<" ";
    }
    else if(root->left != NULL){
        rightB(root->left);
        cout<<root->data<<" ";
    }

}
void printBoundary(Node *root)
{
     //Your code here

    if (root==NULL)
        return;

    cout<<root->data<<" ";

    leftB(root->left);
    leaves(root->left);
    leaves(root->right);
    rightB(root->right);
}
