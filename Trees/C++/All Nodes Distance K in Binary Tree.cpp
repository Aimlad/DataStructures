//All Nodes Distance K in Binary Tree
//https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    void Down(TreeNode* root,int n,int K,vector<int> &res){

        if(root==NULL)
            return;

        if(n==K){
            res.push_back(root->val);
            return;
        }



        Down(root->left,n+1,K,res);
        Down(root->right,n+1,K,res);

    }

    int findTarget(TreeNode* root, TreeNode* target, map<TreeNode*, int> &mp){
        if(root==NULL)
            return -1;
        if(root == target)
            return 1;
        int left=findTarget(root->left,target,mp);
        int right=findTarget(root->right,target,mp);

            if(left == -1 && right== -1)
                return -1;
            else{
                mp[root]=left!=-1 ? left : right;
                return mp[root]+1;
            }
    }

    void Traverse(TreeNode* root, TreeNode* target,vector<int> &res,map<TreeNode*, int> &mp,int dist,int k){
        if(root==NULL)
            return;

        if(root==target)
            return;

        if(mp.find(root)!=mp.end())
            dist=mp[root];

        if(dist==k){
            res.push_back(root->val);
        }

        Traverse(root->left,target,res,mp,dist+1,k);
        Traverse(root->right,target,res,mp,dist+1,k);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        vector<int> res;

        if(root==NULL)
            return res;

        Down(target,0,K,res);

        map<TreeNode*, int> mp;

        int dist=findTarget(root,target,mp);

        Traverse(root,target,res,mp,dist,K);

        return res;

    }
};
