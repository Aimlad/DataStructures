//Detect Cycle in a undirected graph

bool bfs(int s, vector<int> adj[], int V, vector<bool> &vis,vector<int> &inQ){

    queue<int> q;
    int temp;
    inQ[s]=1;
    q.push(s);
    while(!q.empty()){
        s=q.front();
        q.pop();
        inQ[s]=-1;
        vis[s]=true;
        temp=s;
        for(auto it= adj[s].begin();it!=adj[s].end();it++){
            if(*it == temp)
                return true;
            if(!vis[*it] && inQ[*it]!=-1){
                return true;
            }
            else if(!vis[*it] && inQ[*it]==-1){
                q.push(*it);
                inQ[*it]=1;
            }
        }

    }
    return false;
}

bool isCyclic(vector<int> adj[], int V)
{
   // Your code here
    vector<bool> vis(V);
    vector<int> inQ(V);
    for(int i=0;i<V;i++){
        vis[i]=false;
        inQ[i]=-1;
    }
    bool flag=false;
    for(int i=0;i<V;i++){
        if(!vis[i]){
            flag= flag or bfs(i,adj,V,vis,inQ);
            if(flag==true)
                return true;
        }
    }
    return false;

}
