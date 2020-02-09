//Chocolate Distribution Problem

#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	int tc;cin>>tc;
	while(tc--){
	    int n,s;cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    cin>>s;

	    sort(arr,arr+n);
	    int min=INT_MAX;
	    int i=0;
	    while(s+i-1 <n){
	        if(min > arr[s+i-1]-arr[i])
	            min=arr[s+i-1]-arr[i];
	        i++;
	    }
	    cout<<min<<endl;
	}
	return 0;
}
