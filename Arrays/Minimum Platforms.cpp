//Minimum Platforms

#include<bits/stdc++.h>
using namespace std;

int main()
 {
	//code
	int tc;cin>>tc;
	while(tc--){
	    int n;cin>>n;
      int max=0;
	    int arr[n],dep[n];
	    for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int i=0;i<n;i++)
            cin>>dep[i];
	    sort(arr,arr+n);
	    sort(dep,dep+n);
      int i=0,j=0,count=0;
      while(i<n && j<n){
        if(max<count)
          max=count;
        if(arr[i]<=dep[j]){
          count++;
          i++;
        }
        else{
          count--;
          j++;
        }
      }
      cout<<max<<endl;
	}
	return 0;
}
