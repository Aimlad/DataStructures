//Flattening a ll


Node *merge(Node* root1, Node*root2){
Node *result;
if(root1==NULL)
    return root2;
if(root2==NULL)
    return root1;
if(root1->data < root2->data){
    result=root1;
    result->bottom=merge(root1->bottom,root2);
}
else{
    result=root2;
    result->bottom=merge(root1,root2->bottom);
}
return result;
}
Node *flatten(Node *root)
{
// Your code here
if(root==NULL || root->next==NULL)
    return root;
return merge(root, flatten(root->next));
}
