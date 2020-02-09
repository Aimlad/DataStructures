//Trapping Rain Water
// Not container RAIN!!

#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
  int tc;cin>>tc;
  while(tc--){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
      cin>>arr[i];
    }
    int l[n],r[n];
    int max=0;
    for(int i=0;i<n;i++){
      if(arr[i]>max){
        l[i]=arr[i];
        max=arr[i];
      }
      else
        l[i]=max;
      }
    max=0;
    for(int j=n-1;j>=0;j--){
      if(arr[j]>max){
        r[j]=arr[j];
        max=arr[j];
      }
      else
        r[j]=max;
    }
    int sum=0;
    for(int i=0;i<n;i++){
      sum+=min(l[i],r[i])-arr[i];
    }
    cout<<sum<<endl;

  }
	return 0;
}
