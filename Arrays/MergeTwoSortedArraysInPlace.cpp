//Merge Without Extra Space
//Given two sorted arrays arr1[] and arr2[] in non-decreasing order with size n and m.
//The task is to merge the two sorted arrays into one sorted array (in non-decreasing order).


#include<bits/stdc++.h>
using namespace std;

int nextGap(int n){
    if(n<=1)
        return 0;

    return ceil(n/2);
}

int main()
 {
	//code
	int tc;cin>>tc;
	while(tc--){
	    int n,m;
	    cin>>n>>m;
	    vector <int> arr1(n);
	    vector <int> arr2(m);

	    for(int i=0;i<n;i++)
	        cin>>arr1[i];
	    for(int i=0;i<m;i++)
	        cin>>arr2[i];

	    int gap = n+m;
	    for( gap = nextGap(gap) ; gap > 0 ; gap = nextGap(gap)){
	        //cout<<"****";
	        int i=0,j=0;
	        for(i=0;i+gap < n ;i++){
	            if(arr1[i] > arr1[i+gap]){
	                swap(arr1[i], arr1[i+gap]);
	                //cout<<"&&";
	            }
	        }

	        for(j = gap > n ? gap-n : 0 ; i< n && j<m ; i++, j++){
	            if(arr1[i] > arr2[j])
	                swap(arr1[i],arr2[j]);
	        }

	        if(j<m){

	            for(j=0; j+gap < m; j++){
	                if(arr2[j] > arr2[j+gap])
	                    swap(arr2[j], arr2[j+gap]);
	            }

	        }

	    }

	    for(int i=0;i<n;i++)
	        cout<<arr1[i]<<" ";
	    for(int i=0;i<m;i++)
	        cout<<arr2[i]<<" ";
	    cout<<endl;
	}
	return 0;
}
