//Equilibrium point

using namespace std;
int main()
 {
	//code
	int tc;cin>>tc;
	while(tc--){
	    int n;cin>>n;
	    int arr[n];
	    int sum=0, Lsum=0;
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	        sum+=arr[i];
	    }
	    for(int i=0;i<n;i++){
	        sum-=arr[i];
	        if(Lsum==sum){
	            cout<<i+1<<endl;
	            break;
	        }
	        Lsum+=arr[i];
	    }
	    if(Lsum!=sum){
	        cout<<-1<<endl;
	    }

	}
	return 0;
}
