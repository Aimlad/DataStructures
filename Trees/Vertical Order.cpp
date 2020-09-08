//Vertical Order traversal
//Note: Use Level order to maintain the order & sequence of nodes

void helper(Node *root,int n){
    map <int,vector<int> > mp;
    queue<pair<int,Node *>> q;
    q.push({n,root});
    while(true){
        int size=q.size();
        if(size==0)
            break;
        while(size>0){
            pair<int,Node *> p=q.front();
            q.pop();
            mp[p.first].push_back(p.second->data);
            if(p.second->left!=NULL)
                q.push({p.first-1,p.second->left});
            if(p.second->right!=NULL)
                q.push({p.first+1,p.second->right});
            size--;
        }
    }

    for(auto it=mp.begin(); it!=mp.end();++it)
        for(auto i= it->second.begin(); i!= it->second.end(); ++i)
            cout<<*i<<" ";
}

void verticalOrder(Node *root)
{
    if(root==NULL)
        return;
    helper(root,0);
}
