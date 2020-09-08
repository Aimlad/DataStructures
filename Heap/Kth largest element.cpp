//Kth largest element in a stream

#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	int tc;cin>>tc;
	while(tc--){
	    int n,k;
	    cin>>k>>n;
	    int count=0;
	    priority_queue <int, vector <int>, greater <int> > pq;
	    for(int i=0;i<n;i++){
	        int a;cin>>a;
	        count++;
	        // Elements pushing to the min heap
	        // We already have k elements in heap and greater element comes
	        // then the kth largest will get updated.
	        // So, we push element and pop the top
	        if(pq.size()==k && a>pq.top()){
	            pq.push(a);
	            pq.pop();
	        }

	        // If there are less than k elements in heap
	        else if(pq.size()<k){
	            pq.push(a);
	        }

	        // If there are less than k element, so kth largest cannot be found
	        if(count<k){
	            cout<<-1<<" ";
	        }
	        // Else the nth largest in on the top
	        else{
	            cout<<pq.top()<<" ";
	        }
	    }
	    cout<<endl;
	}
	return 0;
}
