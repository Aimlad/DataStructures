//Mirror Tree

bool isIdentical(Node* r1, Node* r2){
    if(r1==NULL && r2==NULL)
        return true;
    if(r1==NULL || r2==NULL)
        return false;

    if(r1->data==r2->data)
        return isIdentical(r1->left,r2->right) &&
            isIdentical(r1->right,r2->left);
    else
        return false;
}

bool isSymmetric(struct Node* root)
{
	// Code here
	return isIdentical(root,root);

}


//Bit Modif

bool isIdentical(Node* r1, Node* r2){
    if(r1==NULL && r2==NULL)
        return true;

    if(r1!=NULL && r2!=NULL && r1->data==r2->data)
        return isIdentical(r1->left,r2->right) &&
            isIdentical(r1->right,r2->left);
    else
        return false;
}

bool isSymmetric(struct Node* root)
{
	// Code here
	return isIdentical(root,root);

}
