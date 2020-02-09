//Reverse array in groups
#include<bits/stdc++.h>
using namespace std;

void rev(int arr[],int beg, int end){
    int i=beg,j=end-1,tmp;
    while(i<j){
        tmp=arr[i];
        arr[i]=arr[j];
        arr[j]=tmp;
        i++;j--;
    }
}
int main()
 {
	//code
	int tc;cin>>tc;
	while(tc--){
	    int n;int k;
	    cin>>n>>k;
	    int arr[n];
	    for(int i=0;i<n;i++)
	        cin>>arr[i];
	    int i=0;
	    while(i+k<n){
	        rev(arr,i,i+k);
	        i=i+k;
	    }
	    if(i<n)
	        rev(arr,i,n);
	    for(int i=0;i<n;i++)
	        cout<<arr[i]<<" ";
	    cout<<endl;
	}
	return 0;
}
