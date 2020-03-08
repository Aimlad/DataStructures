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
	            rev(i,j);    // for end
	        }
	        else if(s[j]=='.'){
	            rev(i,j-1);
	            i=j+1;   // to split individual word separated by .
	        }
	        j++;
	    }
	    //cout<<s<<endl;
	    rev(0,len-1); //Reverse the whole string
	    cout<<s<<endl;
	}
	return 0;
}
