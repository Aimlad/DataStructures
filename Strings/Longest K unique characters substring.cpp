#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	int hash[256];
	int tc;cin>>tc;
	while(tc--){
	    string s;cin>>s;
	    int k; cin>>k;
	    for(int i=0;i< 256;i++)
	        hash[i]=0;
	    int start = 0, count=0, ans = -1, str = -1;
	    for(int end=0; end< s.size(); end++){
	        hash[s[end]]--;
	        if (hash[s[end]] == -1){
	            count++;
	        }
	        if (count > k){
	            // do something
	            while (hash[s[start]] < 0 &&  count>k){
	                hash[s[start]]++;
	                if (hash[s[start]] == 0){
	                    count--;
	                }
	                start++;
	            }
	        }
	        if (count == k){
	            if (ans < end-start+1){
	                ans = end-start+1;
	                str = start;
	            }
	       }
	    }
	    cout << ans << endl;
	}
	return 0;
}
