//SubsetOfAnotherArray

#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	int tc;cin>>tc;
	while(tc--){
	    int n,m;cin>>n>>m;
	    map<int,int> mp;

	    for(int i=0;i<n;i++){
	        int a;cin>>a;
	        mp[a]=1;
	    }
	    bool flag=true;
	    for(int i=0;i<m;i++){
	        int a;cin>>a;
	        if(mp.find(a)!=mp.end()){
	            flag=flag&&true;
	        }
	        else{
	            flag=flag&&false;
	        }
	    }

	    if(flag==false)
	        cout<<"No";
	    else
	        cout<<"Yes";
	    cout<<endl;
	}
	return 0;
}
