//Array to BST
//https://practice.geeksforgeeks.org/problems/array-to-bst/0

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data)
{
  // Allocate memory for new node
  struct Node* node = (struct Node*)malloc(sizeof(struct Node));

  // Assign data to this node
  node->data = data;

  // Initialize left and right children as NULL
  node->left = NULL;
  node->right = NULL;
  return(node);
}

void Preorder(Node *root){
    if(root==NULL)
        return;

    cout<<root->data<<" ";
    Preorder(root->left);
    Preorder(root->right);

    return;
}

Node * create(vector<int> &arr,int start, int end){
    if(start>end)
        return NULL;
    int mid= start+(end-start)/2;
    struct Node * node= newNode (arr[mid]);
    node->left=create(arr,start,mid-1);
    node->right=create(arr,mid+1,end);
    return node;
}

int main()
 {
	//code
	int tc;cin>>tc;
	while(tc--){
	    int n;cin>>n;
	    vector<int> arr(n);

	    for(int i=0;i<n;i++)
	        cin>>arr[i];

        Node * root=create(arr,0,n-1);

        Preorder(root);
        cout<<endl;
	}
	return 0;

}
