//Longest Consecutive Subsequence

#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	int tc;cin>>tc;
	while(tc--){
	    int n;cin>>n;
	    vector<int> arr(n);

	    int max=0;
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	        if(arr[i]>max)
	            max=arr[i];
	    }

	    int hash_table[max];
	    for(int i=0;i<=max;i++){
	        hash_table[i]=-1;
	    }

	    for(int i=0;i<n;i++){
	        hash_table[arr[i]]=1;
	    }
	    int max_count=0,cur_count=0;
	    for(int i=0;i<=max;i++){
	        if(hash_table[i]==-1){
	            cur_count=0;
	        }
	        else{
	            cur_count++;
	        }

	        if(cur_count>max_count)
	            max_count=cur_count;
	    }

	    cout<<max_count<<endl;

	}
	return 0;
}
