/*

Solution:
Base 26 representation of 676 is : 100

*/



#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int tc;cin>>tc;
	int A[1000];
	while(tc--){
		int n;cin>>n;
		string s="";
		int i=0;
        while(n>0){
            A[i]= n%26;
            n=n/26;
            i++;
        }

        for(int j=0;j<i-1; j++){
            if(A[j] <= 0){
                A[j] = A[j] + 26;
                A[j+1] = A[j+1]-26;
            }
        }

        for(int j= i; j>=0; j--){
        	if(A[j] > 0)
            	s = s+ char(64 + A[j]);
        }
        cout<<s<<endl;
	}
	return 0;
}
