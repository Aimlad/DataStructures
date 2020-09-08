//MinIndexedChar

#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	int tc;cin>>tc;
	while(tc--){
	    string str,patt;
	    cin>>str>>patt;
	    unordered_map<char,int> mp;
	    for(int i=0;i<str.size();i++){
	        if(mp.find(str[i])==mp.end()){
	            mp[str[i]]=i;
	        }
	    }
	    int min=INT_MAX;
	    char ch;
	    for(int i=0;i<patt.size();i++){
	        if(mp.find(patt[i])!=mp.end()){
	            if(mp[patt[i]]<min){
	                min=mp[patt[i]];
	                ch=patt[i];
	            }
	        }
	    }

	    if(min==INT_MAX){
	        cout<<"$";
	    }
	    else{
	        cout<<ch;
	    }
	    cout<<endl;
	}
	return 0;
}
