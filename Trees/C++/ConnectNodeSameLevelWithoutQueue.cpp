//https://leetcode.com/problems/populating-next-right-pointers-in-each-node/submissions/
//116. Populating Next Right Pointers in Each Node

void connect(TreeLinkNode *root) {
    if(root == NULL)
        return;

    if(root->left != NULL) root->left->next = root->right;
    if(root->right != NULL && root->next != NULL) root->right->next = root->next->left;


    connect(root->left);
    connect(root->right);
    }
