//Stock buy and sell
/*2
7
100 180 260 310 40 535 695
10
23 13 25 29 33 19 34 45 65 67*/

// 2
// 50 20

#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
  int tc;cin>>tc;
  while(tc--){
    int n,i;
    bool flag=false;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int min=INT_MAX, max=INT_MIN;
    int min_index=0, max_index=-1;
    for(i=0;i<n;i++){
      if(arr[i]< min && arr[i]<max && max_index>min_index){
        cout<<"("<<min_index<<" "<<max_index<<") ";
        min=arr[i];min_index=i;max= INT_MIN;
      }
      else if(arr[i]<=min){
        min=arr[i];min_index=i;
        max=arr[i];max_index=i;
      }
      else if(arr[i] > max){
        max=arr[i];
        max_index=i;
      }
      else if(arr[i]< max){
          flag=true;
        cout<<"("<<min_index<<" "<<max_index<<") ";
        min=arr[i];min_index=i;max= INT_MIN;
      }

    }
    if(max!=INT_MIN && max>min)
        cout<<"("<<min_index<<" "<<n-1<<") ";
    else if(flag==false)
        cout<<"No Profit";
    cout<<endl;
  }
	return 0;
}
