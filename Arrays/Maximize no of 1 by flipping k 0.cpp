//Maximize no of 1 by flipping k 0

#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	int tc;cin>>tc;
	while(tc--){
	    int n,k;cin>>n;
	    vector<int> arr(n);
	    for(int i=0;i<n;i++)
	        cin>>arr[i];
	    cin>>k;

	    int zero_count=0, res=0, zero_index=0;

	    for(int i=0;i<n;i++){
	        if(arr[i]==0)
	            zero_count++;

            if(zero_count > k){
                while(zero_index<=i && arr[zero_index]!=0)
                    zero_index++;
                zero_index++;
                zero_count--;
            }

            res=max(res,i-zero_index+1);
	    }
	    cout<<res<<endl;
	}
	return 0;
}
