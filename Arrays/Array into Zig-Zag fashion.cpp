//array into Zig-Zag fashion

#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	int tc;cin>>tc;
	while(tc--){
	    int n;cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	        cin>>arr[i];

	    for(int i=0;i<n;i++){
	        if(i%2==0 && i+1<n){
	            if(arr[i]>arr[i+1])
	                swap(arr[i],arr[i+1]);
	        }
	        else if(i%2==1 && i+1<n){
	            if(arr[i]<arr[i+1])
	                swap(arr[i],arr[i+1]);
	        }

	    }
	    for(int i=0;i<n;i++)
	        cout<<arr[i]<<" ";
	    cout<<endl;
	}
	return 0;
}
