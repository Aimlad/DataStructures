/*

* Given a BST , replace all its node with its next greater element (i.e successor )
*
* Example :
*         20                        22
*       /   \                     /   \
*      8     22                  12     24
*     /\     /\      ->>        / \    / \
*    4  12  21 24              8   14 22  24
*      /  \                       / \
*     10  14                     12  20
*
* Solution :
*
* 1. Keep global prev Node
* 2. replace prev with current
*
*/



void replace(Node* root){
    static Node* prev=NULL;
    if(root->left != NULL){
        replace(root->left);
    }
    if(prev==NULL){
        prev=root;
    }
    else{
        prev->data=root->data;
        prev=root;
    }

    if(root->right != NULL){
        replace(root->right);
    }

}
