//Sort an array of 0s, 1s and 2s

// ------ Method 1 : Efficient One - Dutch Flag Algorithm

#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	int tc;cin>>tc;
	while(tc--){
	    int n;cin>>n;int arr[n];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }

	    int low=0,mid=0,high=n-1,temp;
	    while(mid<=high){

	        if(arr[mid]==0)
	        {
	            temp=arr[low];
	            arr[low]=arr[mid];
	            arr[mid]=temp;
	            mid++;
	            low++;
	        }
	        else if(arr[mid]==2){
	            temp=arr[high];
	            arr[high]=arr[mid];
	            arr[mid]=temp;
	            high--;
	        }
	        else
	            mid++;
	    }
	    for(int i=0;i<n;i++)
	        cout<<arr[i]<<" ";
	    cout<<endl;
	}
	return 0;
}
// ----Method 2 : Counting -----
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
