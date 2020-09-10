//https://www.geeksforgeeks.org/sum-of-cousin-nodes-of-a-given-node-in-a-bst/
/*
Solution :
1: Do levelOrderTraversal and only insert children into the queue if both are not equal to keyFound
2: If any of them == key, dont insert both. But, Insert the siblings
3: Now as keyFound is true, keep popping values in queue till empty and add to res
*/
int cousinSum(Tree* root, int key){
    if(root==NULL || root->data==key)
        return -1;

    queue<Tree*> q;
    q.push(root);
    bool keyFound = false;
    while(true){
        int size=q.size();
        if(size==0)
            break;

        while(size>0){
            Tree * tmp = q.front();
            q.pop();
            size--;
            if((tmp->left && tmp->left->data ==key) ||
                (tmp->right && tmp->right->data==key)){
                keyFound=true;
            }
            else{
                if(tmp->left)
                    q.push(tmp->left);
                if(tmp->right)
                    q.push(tmp->right);
                }
            }
            if(keyFound)
                break;
        }
        int res=0;
        if(keyFound){
            if(q.empty())
                return -1;
            while(!q.empty()){
                res=res+q.front()->data;
                q.pop();
            }
        }
        return res;
}


/*
Runnable Code
// C++ program to find the sum of cousins
// of a node of a given BST
#include <bits/stdc++.h>
using namespace std;

// structure to store the binary tree
struct Tree {
	int data;
	struct Tree *left, *right;
};

// insertion of node in the binary tree
struct Tree* newNode(int data)
{
	// allocates memory
	struct Tree* node = (struct Tree*)malloc(sizeof(struct Tree));

	// initializes data
	node->data = data;

	// marks the left and right
	// child as NULL
	node->left = node->right = NULL;

	// Return the node after allocating memory
	return (node);
};

// Function which calculates the sum of the cousin Node
int SumOfCousin(struct Tree* root, int p,
				int level1, int level)
{
	int sum = 0;
	if (root == NULL)
		return 0;

	// nodes which has same parent
	// as the given node will not be
	// taken to count for calculation
	if (p == root->data)
		return 0;

	// if the level is same
	// then it is a cousin
	// as parent checking has been
	// done above
	if (level1 == level)
		return root->data;

	// traverse in the tree left and right
	else
		sum += SumOfCousin(root->left, p, level1 + 1, level) + SumOfCousin(root->right, p, level1 + 1, level);

	return sum;
}

// Function that returns the parent node
int ParentNode(struct Tree* root, int NodeData)
{
	int parent = -1;

	// traverse the full Binary tree
	while (root != NULL) {

		// if node is found
		if (NodeData == root->data)
			break;

		// if less than move to left
		else if (NodeData < root->data) {
			parent = root->data;
			root = root->left;
		}

		// if greater than move to rigth
		else {
			parent = root->data;
			root = root->right;
		}
	}

	// Node not found
	if (root == NULL)
		return -1;
	else
		return parent;
}

// Function to find the level of the given node
int LevelOfNode(struct Tree* root, int NodeData)
{
	// calculate the level of node
	int level = 0;
	while (root != NULL) {

		// if the node is found
		if (NodeData == root->data)
			break;

		// move to the left of the tree
		if (NodeData < root->data) {
			root = root->left;
		}

		// move to the right of the tree
		else {
			root = root->right;
		}

		// increase the level after every traversal
		level++;
	}

	// return the level of a given node
	return level;
}
int cousinSum(Tree* root, int key){
    if(root==NULL || root->data==key)
        return -1;

    queue<Tree*> q;
    q.push(root);
    bool keyFound = false;
    while(true){
        int size=q.size();
        if(size==0)
            break;

        while(size>0){
            Tree * tmp = q.front();
            q.pop();
            size--;
            if((tmp->left && tmp->left->data ==key) ||
                (tmp->right && tmp->right->data==key)){
                keyFound=true;
            }
            else{
                if(tmp->left)
                    q.push(tmp->left);
                if(tmp->right)
                    q.push(tmp->right);
                }
            }
            if(keyFound)
                break;
        }
        int res=0;
        if(keyFound){
            if(q.empty())
                return -1;
            while(!q.empty()){
                res=res+q.front()->data;
                q.pop();
            }
        }
        return res;
}
// Driver Code
int main()
{

	// initialize the root as NULL
	struct Tree* root = NULL;

	// Inserts node in the tree
	// tree is the same as the one in image
	root = newNode(15);
	root->left = newNode(13);
	root->left->left = newNode(12);
	root->left->right = newNode(14);
	root->right = newNode(20);
	root->right->left = newNode(18);
	root->right->right = newNode(22);

	// Given Node
	int NodeData = 12;
    cout<<cousinSum(root,NodeData);

	return 0;
}

*/
