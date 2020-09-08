#include<bits/stdc++.h>
using namespace std;
bool visited[101][101];
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
            visited[temp.first][temp.second]=true;
            arr[temp.first][temp.second]=2;
            if((temp.first)+1<m && (temp.second)<n && !visited[(temp.first)+1][temp.second] && arr[(temp.first)+1][temp.second]!=0)
                q.push({(temp.first)+1,temp.second});
            if((temp.first)-1>=0 && (temp.second)<n && !visited[(temp.first)-1][temp.second] && arr[(temp.first)-1][temp.second]!=0)
                q.push({(temp.first)-1,temp.second});
            if((temp.first)<m && (temp.second)+1<n && !visited[temp.first][(temp.second)+1] && arr[temp.first][(temp.second)+1]!=0)
                q.push({temp.first,(temp.second)+1});
            if((temp.first)<m && (temp.second)-1>=0 && !visited[temp.first][(temp.second)-1] && arr[temp.first][(temp.second)-1]!=0)
                q.push({temp.first,(temp.second)-1});

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
	    int n, m;cin>>m,n;

        for(int i=0;i<m;i++)
	        for(int j=0;j<n;j++)
	            cin>>arr[i][j];

	    for(int i=0;i<m;i++)
	        for(int j=0;j<n;j++)
	            visited[m][n]=false;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j] && arr[i][j]==2)
                    q.push({i,j});
            }
        }
        cout<<scatter(m,n,q)<<endl;
	}
	return 0;
}
