//Identical Trees

bool isIdentical(Node *r1, Node *r2)
{
    //Your Code here
    bool result=true;

    if(r1==NULL && r2==NULL)
        return true;
    else if((r1==NULL && r2!=NULL)||(r1!=NULL && r2==NULL))
        return false;


    if(r1->data==r2->data){
        result=result && isIdentical(r1->left,r2->left);
        result=result && isIdentical(r1->right,r2->right);
    }
    else{
        return false;
    }


    return result;
}

// Cleaner Form

bool isIdentical(Node *r1, Node *r2)
{
    //Your Code here
    if(r1==NULL && r2==NULL)
        return true;
    else if(r1==NULL || r2==NULL)
        return false;

    if(r1->data==r2->data){
        return isIdentical(r1->left,r2->left)&&
            isIdentical(r1->right,r2->right);
    }
    else{
        return false;
    }
}
