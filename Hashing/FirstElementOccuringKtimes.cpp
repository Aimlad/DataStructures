//First Element to occur exactly K number of times

#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	int tc;cin>>tc;
	while(tc--){
	    int n,k;cin>>n>>k;
	    unordered_map<int,pair<int,int>> mp;
	    bool flag=true;
	    for(int i=0;i<n;i++){
	        int a;cin>>a;
	        if(mp.find(a)!=mp.end())
	            mp[a].second++;
	        else{
	            mp[a].first=i;
	            mp[a].second++;
	        }
	    }
	    int index=INT_MAX;
	    int res;
	    for(auto it=mp.begin();it!=mp.end();it++){
	        if(it->second.second ==k && it->second.first < index){
	            index=it->second.first;
	            res=it->first;
	        }
	    }
	    if(index==INT_MAX)
	        cout<<-1;
	    else
	        cout<<res;
	    cout<<endl;
	}
	return 0;
}
