/*
1 : Find the Xor value of x and y, lets say (temp)
2 : Find the first set bit of temp and assume it as set_bit
        int set_bit = temp & ~(temp-1);

        // example for get rightmost set bit
        x:             01110000
        ~x:            10001111
        -x or ~x + 1:  10010000
        x & -x:        00010000

        // example for unset rightmost set bit
        x:             01110000
        x-1:           01101111
        x & (x-1):     01100000
3 : Now divide the original array into two part
    1st part : the elements having set bit at exact position as in set_bit variable by (Bitwise AND)
    2nd part : the elements having 0 at exact position as in set_bit variable

4 : Variable left in x and y can be found similarly.
*/

#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	int tc;
	cin>>tc;
	while(tc--){
	    int n;cin>>n;
	    n=2*n+2;
	    int arr[n];

	    cin>>arr[0];
	    int temp = arr[0];
	    for(int i=1;i<n;i++){
	        cin>>arr[i];
	        temp=temp xor arr[i];
	    }
	    int x =0, y=0;
	    int set_bit = temp & ~(temp-1);

	    for(int i=0;i<n;i++){
	        if(arr[i] & set_bit)
	            x= x xor arr[i];
	        else
	            y= y xor arr[i];
	    }

	    cout<<x<<" "<<y<<endl;
	}
	return 0;
}
