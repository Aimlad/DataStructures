//Swapping pairs make sum equal


#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	int tc;cin>>tc;
	while(tc--){
	    int n1,n2;cin>>n1>>n2;
	    int diff;
	    vector<int> v1(n1);
	    vector<int> v2(n2);
	    long long sum1=0,sum2=0;
	    for(int i=0;i<n1;i++){
	        cin>>v1[i];
	        sum1+=v1[i];
	    }
	    for(int i=0;i<n2;i++){
	        cin>>v2[i];
	        sum2+=v2[i];
	    }
	    bool flag=false;
	    map<int,int> mp;
	    if(abs(sum1-sum2)%2==0){
	        if(sum1>sum2){
	            int diff=(sum1-sum2)/2;
	            for(int i=0;i<n2;i++){
	                if (mp.find(v2[i])==mp.end())
	                    mp[v2[i]]=1;
	            }
	            for(int i=0;i<n1;i++){
	                if(mp.find(v1[i]-diff)!=mp.end()){
	                    flag=true;
	                    break;
	                }
	            }

	        }
	        else{
	            diff=(sum2-sum1)/2;
	            for(int i=0;i<n1;i++){
	                if (mp.find(v1[i])==mp.end())
	                    mp[v1[i]]=1;
	            }
	            for(int i=0;i<n2;i++){
	                if(mp.find(v2[i]-diff)!=mp.end()){
	                    flag=true;
	                    break;
	                }
	            }
	        }
	    }
	    if(flag==false && diff!=0)
	        cout<<-1;
	    else
	        cout<<1;
	    cout<<endl;
	}
	return 0;
}
