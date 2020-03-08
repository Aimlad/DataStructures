//Anagram
/*Given two strings a and b consisting of lowercase characters.
The task is to check whether two given strings are anagram of
each other or not. An anagram of a string is another string that
contains same characters, only the order of characters can be different.
For example, “act” and “tac” are anagram of each other.*/

#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	int tc;cin>>tc;
	while(tc--){
	    string str1,str2;
	    cin>>str1>>str2;
	    int arr1[26];int arr2[26];
	    for(int i=0;i<26;i++){
	        arr1[i]=0;
	        arr2[i]=0;
	    }

	    int n1=str1.length();
	    int n2=str2.length();
	    bool flag=false;
	    if(n1!=n2){
	        flag=false;
	    }
	    else{
    	    for(int i=0;i<n1;i++){
    	        arr1[int(str1[i])%97]+=1;
    	    }
    	    for(int i=0;i<n1;i++){
    	        arr2[int(str2[i])%97]+=1;
    	    }
    	    for(int i=0;i<n1;i++){
    	        if(arr1[i]==arr2[i])
    	            flag=true;
    	        else{
    	            flag=false;
    	            break;
    	        }
    	    }
	    }
	    if(flag)
	        cout<<"YES"<<endl;
	    else
	        cout<<"NO"<<endl;

	}
	return 0;
}
