// Maximum of all subarrays of size k
// Monotonic queue
// Concept is to keep the deque in strictly decreasing order and maintaining it
// throughout the input.
// Value at the front it always the greatest for that particular window


#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	int tc;cin>>tc;
	while(tc--){
	    int n,k;
	    cin>>n>>k;
	    int arr[n];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }

	    deque <int> q;
	    for(int i=0;i<k;i++){
	        while(!q.empty() && arr[q.back()] < arr[i]){
	            q.pop_back();
	        }
	        q.push_back(i);
	    }

	    cout<<arr[q.front()]<<" ";

	    for(int i=k;i<n;i++){
	        while(!q.empty() && arr[q.back()] < arr[i]){
	            q.pop_back();
	        }

	        q.push_back(i);

	        while(!q.empty() && q.front()<=i-k && i-k>=0){
	            q.pop_front();
	        }
	        if(!q.empty() && i>=k){
	            cout<<arr[q.front()]<<" ";
	        }
	    }
	    cout<<endl;
	}
	return 0;
}
