// Rotten Oranges Cleaner

#include<bits/stdc++.h>
using namespace std;
int arr[101][101];
int dx[]={0,-1,0,1};
int dy[]={-1,0,1,0};


int scatter(int m, int n,queue<pair<int,int>> &q){
    int count=0;
    while(true){
        int size=q.size();
        if(size==0){
            break;
        }
        while(size>0){
            pair<int, int> temp;
            temp=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nx=temp.first+dx[i];
                int ny=temp.second+dy[i];
                if(nx<m && nx>=0 && ny<n && ny>=0 && arr[nx][ny]==1){
                    arr[nx][ny]=2;
                    q.push({nx,ny});
                }
            }
            size--;
        }
        count++;
    }
    return count;
}

int main()
 {
	//code
	int tc;cin>>tc;
	while(tc--){
	    queue<pair<int,int>> q;
	    int n, m;cin>>m>>n;

        for(int i=0;i<m;i++)
	        for(int j=0;j<n;j++)
	            cin>>arr[i][j];

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(arr[i][j]==2)
                    q.push({i,j});
            }
        }
        bool flag=false;
        int result=scatter(m,n,q);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(arr[i][j]==1 && !flag){
                    cout<<-1<<endl;
                    flag=true;
                }
            }
        }
        if(flag==false)
            cout<<result-1<<endl;
	}
	return 0;
}
