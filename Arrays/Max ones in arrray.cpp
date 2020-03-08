//Max ones in array

/* Test Cases :
3
15
1 1 0 1 0 0 1 1 1 1 0 1 1 0 0
5
1 1 1 1 0
7
1 0 1 0 1 0 1
Output:
7
5
3
*/


#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
  int tc;cin>>tc;
  while(tc--){
    int n;cin>>n;
    int arr[n],a;
    int max_len=-1,cur_len=0,sum=0;
    for(int i=0;i<n;i++){
      cin>>a;
      if(a==0)
        arr[i]=1;
      else
        arr[i]=0;
    }

    int j=0,one_idx;
    while(j<n){
      sum=sum+arr[j];
      if(sum<=1){
        cur_len++;
        if(arr[j]==1){
          one_idx=j;
        }
      }
      else{
        if(cur_len>max_len){
          max_len=cur_len;
        }
        cur_len=0;
        sum=0;
        j=one_idx;
        one_idx=-1;
      }
      //cout<<cur_len<<"*"<<one_idx<<endl;
      j++;
      //cout<<j<<"*";
    }
    if(cur_len>max_len)
        max_len=cur_len;
    cout<<max_len<<endl;
  }
	return 0;
}
