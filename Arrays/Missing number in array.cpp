//https://practice.geeksforgeeks.org/problems/missing-number-in-array/0
// Can also be done by N*N+1 /  2

using namespace std;
int main()
 {
	//code
	int tc;
	cin>>tc;
	while(tc--){
	    int n;
	    cin>>n;
	    int sum=0;
	    int val=0;
	    for(int i=1;i<=n;i++){
	        val=val xor i;
	    }
	    
	    int xorv=0;
	    int a;
	    for(int i=1;i<n;i++){
	        cin>>a;
	        xorv=xorv xor a;
	    }
	    
	    cout<<(val xor xorv)<<endl;
	}
	return 0;
}