#include<bits/stdc++.h>
using namespace std;

int dx[]={-1,0,0,1};
int dy[]={0,-1,1,0};
int MX=1000;

void dfs(int **arr,int r,int c,int x,int y,int k){
    int temp=arr[x][y];
    arr[x][y]=k;
    for(int i=0;i<4;i++){
        if(x+dx[i] >=0 && x+dx[i] <r && y+dy[i] >=0 && y+dy[i] <c
        && arr[x+dx[i]][y+dy[i]]==temp)
            dfs(arr,r,c,x+dx[i],y+dy[i],k);
    }
}

int main()
 {
	//code
    int tc;cin>>tc;
    while(tc--){
	    int r,c;
	    cin>>r>>c;
	    int **arr;
	    arr = new int*[r];
	    for(int i=0;i<r;i++){
	        arr[i] = new int[c];
	    }
	    for(int i=0;i<r;i++)
	        for(int j=0;j<c;j++)
	            cin>>arr[i][j];


	    int x,y,k;
	    cin>>x>>y>>k;
	    if(x<r && y<c)
	        dfs(arr,r,c,x,y,k);

	    for(int i=0;i<r;i++){
	        for(int j=0;j<c;j++){
	            cout<<arr[i][j]<<" ";
	        }
	        //cout<<endl;
	    }
	    cout<<endl;
	}
	return 0;
}
