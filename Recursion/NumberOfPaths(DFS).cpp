//NumberOfPaths
//From (0,0) to (r,c)


#include<bits/stdc++.h>
using namespace std;

int dx[]={0,1};
int dy[]={1,0};
bool visited[11][11];

void dfs(vector< vector<int> > &arr,int x, int y,int &count){
    visited[x][y]=true;

    for(int i=0;i<2;i++){
        if(x+dx[i]< arr.size() && y+dy[i] < arr[0].size()
        && !visited[x+dx[i]][y+dy[i]])
            dfs(arr,x+dx[i],y+dy[i],count);
    }
    if(x==arr.size()-1 && y==arr[0].size()-1)
            count++;
    visited[x][y]=false;
}


int main()
 {
	//code
	int tc;cin>>tc;
	while(tc--){
	    int r,c,count=0;
	    cin>>r>>c;

	    for(int i=0;i<r;i++)
	        for(int j=0;j<c;j++)
	            visited[i][j]=false;

	    vector< vector<int> > arr (r, vector<int> (c,0));
	    dfs(arr,0,0,count);
	    cout<<count<<endl;
	}
	return 0;
}
