//Overlapping Intervals

#include<bits/stdc++.h>
using namespace std;

struct interval{
    int s;
    int e;
};

int main()
 {
	//code
	int tc;cin>>tc;
	while(tc--){
	    int n;cin>>n;
	    vector<interval> arr(n);

	    for(int i=0;i<n;i++){
	        cin>>arr[i].s;
	        cin>>arr[i].e;
	    }

	    sort(arr.begin(),arr.end(),
	    [](interval a,interval b){  return a.s < b.s;  });

	    vector <interval> res;
	    res.push_back(arr[0]);

	    for(int i=1;i<n;i++){
	        if(res.back().e < arr[i].s)
	            res.push_back(arr[i]);
	        else
	            res.back().e= max(res.back().e, arr[i].e);
	    }

	    for(int i=0;i<res.size();i++){
	        cout<<res[i].s<<" "<<res[i].e<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
