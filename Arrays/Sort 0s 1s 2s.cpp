//Sort an array of 0s, 1s and 2s

#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	int tc;cin>>tc;
	while(tc--){
	    int n;cin>>n;int arr[n];
	    int zc=0,oc=0,t=0;
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	        if(arr[i]==0)
	            zc++;
	        else if(arr[i]==1)
	            oc++;
	        else
	            t++;
	    }

	    for(int i=0;i<n;i++){
	        if(zc>0){
	            arr[i]=0;
	            zc--;
	        }
	        else if(oc>0){
	            arr[i]=1;
	            oc--;
	        }
	        else{
	            arr[i]=2;
	            t--;
	        }
	    }
	    for(int i=0;i<n;i++)
	        cout<<arr[i]<<" ";
	    cout<<endl;
	}
	return 0;
}
