//https://practice.geeksforgeeks.org/problems/rotate-array-by-n-elements/0
//Rotate array by factor of k
/*
--------------------------
5 2
I/P : 1 2 3 4 5
O/P : 3 4 5 1 2

---------------------------
10 3
I/P : 2 4 6 8 10 12 14 16 18 20
O/P : 8 10 12 14 16 18 20 2 4 6
---------------------------
*/

#include<bits/stdc++.h>
using namespace std;
void reverse(int arr[],int beg, int end){
    int temp;
    while(beg<end){
        temp=arr[beg];
        arr[beg]=arr[end];
        arr[end]=temp;
        beg++;
        end--;
    }
}

int main()
 {
	//code
	int tc;cin>>tc;
	while(tc--){
	    int n,k;cin>>n>>k;
	    int arr[n];
	    for(int i=0;i<n;i++)
	        cin>>arr[i];

	    reverse(arr,0,k-1);
	    reverse(arr,k,n-1);
	    reverse(arr,0,n-1);

	    for(int i=0;i<n;i++)
	        cout<<arr[i]<<" ";
	    cout<<endl;
	}
	return 0;
}
