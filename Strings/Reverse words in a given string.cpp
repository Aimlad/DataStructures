//Reverse words in a given string

#include<bits/stdc++.h>
using namespace std;
string s;
void rev(int i, int j){
    while(i<j){
        char ch;
        ch=s[i];
        s[i]=s[j];
        s[j]=ch;
        i++;
        j--;
    }
    return;
}

int main()
 {
	//code
	int tc;cin>>tc;
	while(tc--){
	    cin>>s;
	    int len= s.length();
	    int i=0,j=0;
	    while(j<len){

	        if(j==len-1){
	            rev(i,j);
	        }
	        else if(s[j]=='.'){
	            rev(i,j-1);
	            i=j+1;
	        }
	        j++;
	    }
	    //cout<<s<<endl;
	    rev(0,len-1);
	    cout<<s<<endl;
	}
	return 0;
}
