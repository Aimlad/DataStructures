// Next larger element
//Storing the o/p in a result array to maintain the order
// Note: Storing the indexes of element instead of storing actual element in the
// stack
#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	int tc;cin>>tc;
	while(tc--){
	    stack <int> s;
	    int n;cin>>n;
	    long long int arr[n],result[n];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }

	    s.push(0);
	    int i=1;
	    while(i<n){
	        if(!s.empty()){
            //compare element at the top of stack with cur element
	            while(!s.empty() && arr[s.top()]<arr[i]){
	                result[s.top()]=arr[i];
	                s.pop();
	            }
	            s.push(i); // if stack is empty or s.top>cur
	        }
	        else{
	        s.push(i); // for initial case when stack is empty
	        }
	        i++;
	    }

      while(i==n && !s.empty()){ // For all those elements whose next larger is not present
	        result[s.top()]=-1;
	        s.pop();
	    }
      i=0;
	    while(i<n){
	        cout<<result[i]<<" ";i++;
	    }
	    cout<<endl;
	}
	return 0;
}
