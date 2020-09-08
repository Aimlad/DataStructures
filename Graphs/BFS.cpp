
void bfs(int s, vector<int> adj[], bool vis[], int N)
{
    // Your code here

    queue<int> q;
    q.push(s);
    while(!q.empty()){
        s=q.front();
        q.pop();
        vis[s]=true;
        cout<<s<<" ";
    for(auto it= adj[s].begin();it != adj[s].end(); it++){
        if(!vis[*it]){
            vis[*it]=true;
            q.push(*it);}
        }
    }

}
