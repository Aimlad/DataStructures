// Longest Distinct characters in string

using namespace std;
int main()
 {
	//code
	int hash[256];
	int tc;cin>>tc;
	while(tc--){
	    string str;
	    cin>>str;
	    for (int i = 0; i < 256; i++){
	        hash[i] = 1;
	    }
	    int start=0,curlen = 0, maxlen=0;

	    for(int i=0;i<str.size();i++){
            hash[str[i]]--;
            if(hash[str[i]]==-1){
                while(hash[str[i]]==-1){
                    // cout<<"yo";
                    hash[str[start]]++;
                    start++;
                }
            }
            curlen=i-start+1;
            if(maxlen<curlen){
                maxlen=curlen;
            }
	    }
	    cout<<maxlen<<endl;
	}
	return 0;
}
