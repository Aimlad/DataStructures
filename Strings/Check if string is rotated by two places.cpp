//Check if string is rotated by two places


using namespace std;
int main()
 {
	//code
	int tc;cin>>tc;
	while(tc--){
	    string str1,str2;
	    cin>>str1>>str2;
	    int n=str1.length();

	    int i=0,j=n-2;
	    bool flag=false;
	    while(i<n){
	        j=j%n;
	        if(str1[i]==str2[j]){
	            i++;j++;
	            flag=true;
	        }
	        else{
	            flag=false;
	            break;
	        }
	    }
	    j=0;i=n-2;
	    if(!flag){
	    while(j<n){
	        i=i%n;
	        if(str1[i]==str2[j]){
	            i++;j++;
	            flag=true;
	        }
	        else{
	            flag=false;
	            break;
	        }
	    }}
	    if(flag)
	        cout<<1;
	    else
	        cout<<0;
	    cout<<endl;

	}
	return 0;
}
