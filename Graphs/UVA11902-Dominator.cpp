#include<bits/stdc++.h>
using namespace std;

bool visited[100];
bool res[101][101];
void dfs(int rem,int start,vector<vector<int>> &adjList){
    visited[start]=true;
    res[rem][start]=false;

    for(auto it = adjList[start].begin();it !=adjList[start].end();it++){
        if(rem != *it && !visited[*it])
            dfs(rem,*it,adjList);
    }
    visited[start]=false;
    return;
}


int main(){
    int tc;cin>>tc;int m=1;
    while(tc--){
    	cout<<"Case "<<m<<":"<<endl;
        int n,a;cin>>n;
        vector<vector<int>> adjList(n);

        for(int i=0;i<n;i++){
            visited[i]=false;
            for(int j=0;j<n;j++){
                cin>>a;
                if(a==1)
                    adjList[i].push_back(j);
                res[i][j]=true;
            }
        }
        for(int i=0;i<n;i++){
            visited[i]=true;
            if(!visited[0])
                dfs(i,0,adjList);
            visited[i]=false;
        }
        for(int i=0;i<n;i++){
        	cout<<"+";
        	for(int x=1;x<=n*2-1;x++)
        		cout<<"-";
        	cout<<"+"<<endl;
            for(int j=0;j<n;j++){
            	if(res[i][j]== 1)
                	cout<<"|Y";
                else
                	cout<<"|N";
            }
            cout<<"|"<<endl;
        }
        cout<<"+";
        	for(int x=1;x<=n*2-1;x++)
        		cout<<"-";
    	cout<<"+"<<endl;
        m++;
    }
    return 0;
}
