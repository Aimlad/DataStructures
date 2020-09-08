
void dfs(int s, vector<int> g[], bool vis[])
{

    vis[s]=true;
    cout<<s<<" ";
    for(auto it=g[s].begin(); it!= g[s].end();it++){
        if(!vis[*it])
            dfs(*it,g,vis);
    }

}
