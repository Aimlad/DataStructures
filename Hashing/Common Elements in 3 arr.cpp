//Common Elements in 3 arr


#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	int tc;cin>>tc;
	while(tc--){
	    int n1,n2,n3,a;
	    cin>>n1>>n2>>n3;
	    map <int, int> mp;

	    for(int i=0;i<n1;i++){
	        cin>>a;
	        mp[a]=1;
	    }
	    for(int i=0;i<n2;i++){
	        cin>>a;
	        if(mp[a]==1)
	            mp[a]=2;
	    }
        for(int i=0;i<n3;i++){
	        cin>>a;
	        if(mp[a]==2)
	            mp[a]=3;;
	    }
	    bool flag=true;
	    for(auto it=mp.begin();it!=mp.end();it++){
	        if(it->second ==3){
	            cout<<it->first<<" ";
	            flag=false;
	        }
	    }

	    if(flag==true)
	        cout<<-1;
	    cout<<endl;
	}
	return 0;
}
