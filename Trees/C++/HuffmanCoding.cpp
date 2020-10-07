/*
Huffman Encoding

Link : https://practice.geeksforgeeks.org/problems/huffman-encoding/0

Given An array of Alphabets and their frequency. Your task is to print all the
given alphabets Huffman Encoding.
Note: If two elements have same frequency, then the element which if at first
will be taken on left of Binary Tree and other one to right.

Input:
First line consists of test cases T. First line of every test case consists of
string of alphabets and second line consists of its frequencies.

Output:
Print the HuffmanCodes in single line, with n spaces of each alphabet's
HuffmanCodes respectively. In PreOrder form of Binary Tree.

Constraints:
1<=T<=100
1<=|String length|<=26

Example:
Input:
1
abcdef
5 9 12 13 16 45
Output:
0 100 101 1100 1101 111

Solution:
Create nodes for each letter and insert into a min heap
Create newNode with 2 minimum popped elements from heap
Final node will be the root of the Tree
Now simply do PreOrder traversal and for each leaf node print vector

*/

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        char data;
        int freq;
        Node* left;
        Node* right;

        Node(char c, int n){
            data=c;freq=n;left=NULL;right=NULL;
        }
};

void print(vector<int> &res){
    for(int i=0;i<res.size();i++){
        cout<<res[i];
    }
    cout<<" ";
}

void traverse(Node * root,vector<int> &res){
    if(root==NULL)
        return;

    if(root->left == NULL && root->right==NULL){
        print(res);
        res.pop_back();
    }
    if(root->left)
    {
        res.push_back(0);
        traverse(root->left,res);
    }
    if(root->right){
        res.push_back(1);
        traverse(root->right,res);
    }
    if(root->left && root->right)
        res.pop_back();
}

struct cmp{
    bool operator()(Node *n1, Node *n2){
        return n1->freq>n2->freq;
    }
};

int main() {
	//code
	int tc;cin>>tc;
	while(tc--){
	    string s;cin>>s;
	    vector<int> v;int a;
	    for(int i=0; i< s.length(); i++){
	        cin>>a;
	        v.push_back(a);
	    }

	    priority_queue<Node*,vector<Node*>, cmp> pq;

	    for(int i=0;i<s.length();i++){
	        Node *newNode = new Node(s[i],v[i]);
	        pq.push(newNode);
	    }

	    while(pq.size() >1){
	        Node *n1 = pq.top();
	        pq.pop();
	        Node *n2 = pq.top();
	        pq.pop();
	        Node *newNode = new Node('#',n1->freq+n2->freq);
	        newNode->left=n1;
	        newNode->right=n2;
	        pq.push(newNode);
	    }
	    //cout<<"ssss";
	    vector<int> arr;
	    Node *res = pq.top();
	    pq.pop();
	    if(res==NULL)
	        return 0;

	    traverse(res,arr);
	    cout<<endl;

	}
	return 0;
}
