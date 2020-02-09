//Leaders in an array 

using namespace std;
int main()
 {
	//code
	int tc;cin>>tc;
	stack <int> s;
	while(tc--){

	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	        cin>>arr[i];
	    s.push(arr[n-1]);
	    int cmp=arr[n-1];
	    for(int i=n-2;i>=0;i--){
	        if(arr[i]>=cmp){
	            s.push(arr[i]);
	            cmp=arr[i];
	        }
	    }
	    while(!s.empty()){
	        cout<<s.top()<<" ";
	        s.pop();
	    }
	    cout<<endl;
	}
	return 0;
}
