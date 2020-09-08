//Serialize & Deserialize Tree

void serialize(Node *root,vector<int> &A)
{
    //Your code here
    if(root==NULL){
        A.push_back(-1);
        return;
    }
    A.push_back(root->data);

    serialize(root->left,A);
    serialize(root->right,A);

}

/*this function deserializes
 the serialized vector A*/

 //We are erasing Array.begin() because everytime we erase the begin,
 // next element will be at index =0, so we wont have to ++ index
int idx=0;
Node * deSerialize(vector<int> &A)
{
   //Your code here
    if(idx>=A.size()){
        return NULL;}
    if(A[idx]==-1){
        A.erase(A.begin());
        return NULL;
    }

    Node * root=new Node(A[idx]);
    A.erase(A.begin());
    root->left=deSerialize(A);
    root->right=deSerialize(A);
    return root;
}
