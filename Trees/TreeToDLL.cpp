//Binary tree to DLL

void bToDLL(Node *root, Node **head_ref)
{
    // your code here
    static Node * prev=NULL;

    if(root==NULL)
        return;

    bToDLL(root->left,head_ref);
    if(*head_ref == NULL){
        prev=NULL;
        *head_ref=root;
    }
    else{
        root->left=prev;
        prev->right=root;
    }
    prev=root;

    bToDLL(root->right,head_ref);
}
