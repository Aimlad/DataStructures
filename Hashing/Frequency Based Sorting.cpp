//Frequency Based Sorting
//Copy can be used to copy map values to vector of pairs




#include<bits/stdc++.h>
using namespace std;

bool comparator(const pair<int,int>& a,const pair<int,int>& b){
    if(a.second==b.second)
        return a.first<b.first;
    return a.second>b.second;
}

void fn(vector<int> &arr,int n){
    unordered_map<int,int> mp;
    vector< pair<int,int> > temp;

        for(int i=0;i<n;i++)
	        mp[arr[i]]+=1;

	    copy(mp.begin(),mp.end(),back_inserter(temp));
	    sort(temp.begin(),temp.end(),comparator);

	    for(int i=0;i<temp.size();++i){
	        for(int j=0;j<temp[i].second;++j){
	            cout<<temp[i].first<<" ";
	        }
	    }
	    cout<<endl;
}

int main(){
	//code
	int tc;cin>>tc;
	while(tc--){
	    int n;cin>>n;
        vector<int> arr(n,0);
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    fn(arr,n);
	    /*for(int i=0;i<n;i++){
	        cout<<arr[i]<<" ";
	    }*/
	}
	return 0;
}
