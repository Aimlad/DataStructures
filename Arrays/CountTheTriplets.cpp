//Count the triplets

#include<bits/stdc++.h>
using namespace std;

void fn(vector<int> arr, int start,int &counter){
    //cout<<counter<<" ";
    int left=start+1;
    int right=arr.size()-1;
    while(left < right){
    if(arr[start]== arr[left] + arr[right]){
        counter++;
        left++;
        right--;
    }
    else if(arr[left] + arr[right] < arr[start]){
        right--;
    }
    else
        left ++;
    }
}
int main()
 {
	//code
	int tc;cin>>tc;
	while(tc--){
	    int n;cin>>n;
	    int counter=0;
	    vector < int > arr(n);
	    for(int i=0;i<n;i++)
	        cin>>arr[i];

	    sort(arr.begin(),arr.end(),greater<int>());

	    for(int i=0;i<n;i++){
	        fn(arr,i,counter);
	       // while(i+1<n && arr[i]==arr[i+1])
	       //     i++;
	    }
	    if(counter==0)
	        cout<<-1;
	    else
	        cout<<counter;
	    cout<<endl;
	}
	return 0;
}
