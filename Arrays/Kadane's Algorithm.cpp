//https://practice.geeksforgeeks.org/problems/kadanes-algorithm

#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	int tc;cin>>tc;
	while(tc--){
	    int max_sum=INT_MIN, cur_sum;
	    int n;cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	        cin>>arr[i];
	    cur_sum=0;

	    for(int i=0;i<n;i++){
	        if(cur_sum<=0)		//If cur_sum <=0 and arr[i] is >0 then simply cur_sum= arr[i] because previous is of no use now
	            cur_sum=arr[i];

	        else
	            cur_sum+=arr[i];			// Else keep adding

	        if(cur_sum>max_sum)				// If cur_sum >max at any point, then max=cur_sum
	            max_sum=cur_sum;

	    }
	    cout<<max_sum<<endl;
	}
	return 0;
}

/*
3
-2 5 -1
O/p : 5
*/
