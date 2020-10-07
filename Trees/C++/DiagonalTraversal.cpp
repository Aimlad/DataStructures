



void traverse(TreeNode* root,int key,map<int,vector<int>> &mp){
    if(root==NULL)
        return;
    mp[key].push_back(root->val);
    
    if(root->left)
        traverse(root->left,key+1,mp);
    if(root->right)
        traverse(root->right,key,mp);
}

vector<int> Solution::solve(TreeNode* A) {
    map<int,vector<int>> mp;
    vector<int>res;
    if(A==NULL)
        return res;
    traverse(A,0,mp);

    for(auto it =mp.begin(); it!= mp.end();it++){
        for(auto vt = it->second.begin(); vt!=it->second.end();vt++){
            res.push_back(*vt);
        }
    }

    return res;

}
