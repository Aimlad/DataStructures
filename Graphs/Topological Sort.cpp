//Topological Sort
//geeksforgeeks
//Also Leetcode 205


void dfs(int s,vector<int> adj[],vector <bool> &visited,stack<int> &res){
    visited[s]=true;
    for(auto it=adj[s].begin(); it!=adj[s].end(); it++){
        if(!visited[*it])
            dfs(*it,adj,visited,res);
    }
    res.push(s);
    return;
}
int* topoSort(int V, vector<int> adj[]) {
    // Your code here
    vector <bool> visited(V);
     for(int i=0;i<V;i++)
        visited[i]=false;
    stack <int> res;
    for(int i=0;i<V;i++){
        if(!visited[i])
            dfs(i,adj,visited,res);
    }

    int *a= new int[V];
    int i=0;
    while(!res.empty()){
        a[i]=res.top();
        res.pop();
        i++;
    }
    return a;
}
