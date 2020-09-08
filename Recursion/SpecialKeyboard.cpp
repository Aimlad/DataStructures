// 4 Key Keyboard
// Special Keyboard
// Dp solution
// Ref: https://www.ideserve.co.in/learn/print-maximum-number-of-a-using-four-keys-of-special-keyboard

/*
If number of allowed keystrokes(N) is less than 7, then the maximum number of As possible is N. You should be able to verify this yourself.

It turns out that for N greater than or equal to 7, to produce maximum number of As, the sequence of N keystrokes that will be used will always end with a suffix of Ctrl-A, Ctrl-C, followed by all Ctrl-V's. We have to basically figure out the point(say critical-point) after which we should use this suffix of Ctrl-A, Ctrl-C, followed by all Ctrl-V's to obtain maximum number of As.

To find out this critical point for input N, we try out each of the values from N-3 to 1 and compute the number of As that are produced after making a value as critical point and then appending it with the suffix of Ctrl-A, Ctrl-C, followed by all Ctrl-V's. While computing maximum number of As possible with each trial critical point(from N-3 to 1) plus above suffix of Ctrl-A, Ctrl-C, followed by all Ctrl-V's, we use maximum number of As already computed for each value(N-3 to 1).

Say f(N) denotes the maximum number of As possible for N keystrokes. Let use see how do we compute f(N) for N = 7.

First we choose critical point 'N_critical' as 4. We already know the value of f(4) which is 4. For remaining 3 keystrokes, we use Ctrl-A, Ctrl-C, Ctrl-V. The string of keystrokes produced will be A,A,A,A,Ctrl-A,Ctrl-C, Ctrl-V. These last 3 keystrokes essentially double the value of f(4). Hence for 'N_critical = 4', we get 8 number of As which is 2*f(4).

Now we choose critical point 'N_critical' as 3. We already know the value of f(3) which is 3. For remaining 4 keystrokes, we use Ctrl-A, Ctrl-C, Ctrl-V, Ctrl-V. The string of keystrokes produced will be A,A,A,Ctrl-A,Ctrl-C, Ctrl-V, Ctrl-V. These last 4 keystrokes essentially triple the value of f(3). Hence for 'N_critical = 3', we get 9 number of As which is 3*f(3).

Similarly, for 'N_critical' = 2, we get 4*f(2) number of As which is 8. And for 'N_critical' = 1, maximum number of As possible is 5*f(1) which is 5.

Therefore choosing 'N_critical' as 3 gives us maximum number of As. In other words, f(7) = 9.

The algorithm basically needs to implement the above recurrence relation where base case is defined as f(N) = N when N < 7. To avoid re-computations of same sub-problems, intermediate results are stored in an array and re-used if required. Please check out function findMaxAs(int n, int[] maxAsSolution) in code snippet for implementation details.
*/



/*
In general,
f(N) = N if N < 7
     = max{2*f(N-3), 3*f(N-4),..., (N-2)*f(1)}
     */
#include<bits/stdc++.h>
using namespace std;

int calculate(int n,int max_arr[]){
    if(n<7)
        return n;
    int multiplier=2,cur_max_arr=0,result=0;
    for(int i=n-3;i>0;i--){
      // If not computed already, then compute it first and store in dp[]
        if(max_arr[i]==-1){
            max_arr[i] = calculate(i,max_arr);
        }

        //Calculating max value possible with that value of i
        cur_max_arr=max_arr[i]*multiplier;
        if(cur_max_arr>result)
            result=cur_max_arr;
        multiplier++;
    }
    return result;
}
int main()
 {
	//code
	int tc;cin>>tc;
	while(tc--){
	    int n;cin>>n;
	    int arr[n];
	    for(int i=1;i<=n;i++){
	        arr[i]=-1;
	    }
        cout<<calculate(n,arr);
	    cout<<endl;
	}
	return 0;
}
