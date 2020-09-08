//First Non-repeating Char in Stream

#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	int tc,minIndex=INT_MAX,nonRepeatingChar,j=0;
	cin>>tc;
	int arr[26];
	while(tc--){
	    int n;
	    cin>>n;

	    for(int i=0;i<26;i++)
	        arr[i]=-1;

	    char ch;
	    for(int i=0;i<n;i++){
	        cin>>ch;
	        if(arr[(int)ch-97]==-1){
	            arr[(int)ch-97]=i;
	        }
	        else if(arr[(int)ch-97]>-1 && arr[(int)ch-97]<INT_MAX){
	            arr[(int)ch-97]=INT_MAX;
	        }
	        for(j=0;j<26;j++){
	            if(arr[j]!=-1 && arr[j]!=INT_MAX){
	                if(arr[j]<minIndex){
	                    nonRepeatingChar=j;
	                    minIndex=arr[j];
	                }
	            }
	        }
	        if(arr[nonRepeatingChar]==-1 || arr[nonRepeatingChar]==INT_MAX)
	            cout<<-1<<" ";
	        else
	            cout<<(char)(nonRepeatingChar+97)<<" ";
	        minIndex=INT_MAX;
	    }
	    cout<<endl;
	}
	return 0;
}
