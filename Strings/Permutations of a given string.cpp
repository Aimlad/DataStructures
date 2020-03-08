//Permutations of a given string
#include<bits/stdc++.h>
using namespace std;


void permute(string str,int beg, int end){

    if (beg==end){
        cout<<str<<" ";
        return;
    }

    else
    {
        for(int i=beg;i<=end;i++)
        {
            swap(str[beg],str[i]);
            sort(str.begin()+beg+1,str.end());
            permute(str,beg+1,end);
            sort(str.begin()+beg+1,str.end());
            swap(str[beg],str[i]);
        }
    }
}

int main()
 {
	//code
	int tc;cin>>tc;
	string str;
	while(tc--){
	    cin>>str;
	sort(str.begin(),str.end());
	permute(str,0,str.length()-1);
	cout<<endl;

	}
	return 0;
}
