//Longest Palindrome in a String

#include<bits/stdc++.h>
using namespace std;
#define MAX 10000

bool dp[MAX][MAX];
int main()
 {
	//code
  int tc;cin>>tc;
  string str;
  while(tc--){
    cin>>str;
    int len=str.length();
    int max_len=1,cur_len=1,start_index=0,j;

    //for Length 1
    for(int i=0;i<len;i++){
      dp[i][i]=true;
    }


//For length==2
    for(int i=0;i<len-1;i++){
        cur_len=2;
      if(str[i]==str[i+1]){
        dp[i][i+1]=true;
        if(max_len<cur_len){
            start_index=i;
            max_len=2;
        }
      }
      else
        dp[i][i+1]=false;
    }

    //for length >=3, if str[beg]==str[end] && dp[beg+1][end-1]==true
    //then true/is pallindrome else false;

    for(int cur_len=3;cur_len<=len;cur_len++){
      for(int i=0;i<len;i++){
        j=i+cur_len-1;
        if(str[j]==str[i] && dp[i+1][j-1]==true){
          dp[i][j]=true;
          if(max_len<cur_len){
            max_len=cur_len;
            start_index=i;
        }
        }
        else{
            dp[i][j]=false;
        }
      }
    }
    //cout<<max_len;
    int count=0;
    for(int i=start_index;count<max_len;i++){
      cout<<str[i];
      count++;
    }
    cout<<endl;
  }
	return 0;
}
