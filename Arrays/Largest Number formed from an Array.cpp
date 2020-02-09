//Largest Number formed from an Array

#include<bits/stdc++.h>
using namespace std;

bool cmp(int a, int b){
    string s1= to_string(a);
    string s2= to_string(b);

    string sa= s1+s2;
    string sb= s2+s1;

    int res1= stoi(sa);
    int res2= stoi(sb);

    return res1>res2;
}

int main()
 {
	//code
	int tc;cin>>tc;
	while(tc--){
	    int n;cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	        cin>>arr[i];

	    sort(arr,arr+n,cmp);

	    for(int i=0;i<n;i++)
	        cout<< arr[i];
	    cout<<endl;
	}
	return 0;
}
