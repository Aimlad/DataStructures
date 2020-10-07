// Pairs which are Divisible by 4
/*
Given an array if ‘n’ positive integers, count number of pairs of integers in the array that have the sum divisible by 4.

https://practice.geeksforgeeks.org/problems/pairs-which-are-divisible-by-4/0

2 Solutions:

Counter :
Recursively select elements and find the value
TC : O(3^n)

Counter1:
Store the frequency of modulo values till k-1 in an array
Case 1 : when freq[0] >1, same can be paired with each other
        Trick : No of ways to select 2 elements from n elements: n* n-1 /2
Case 2 : For all elements from i<j
Case 3 : if k is even then, elements at freq[ K/2 ] can be clubbed together
        So, Same as case 1, (n*n-1/2), for freq[k/2];

*/

#include<bits/stdc++.h>
using namespace std;

int counter(int arr[],int k, int n, int count, int sum){
    //cout<<sum<<"!"<<n<<endl;
    if(count ==0 && sum % k == 0){
        //cout<<"Found"<<endl;
        return 1;
    }
    if(count == 0)
        return 0;
    if(n==0)
        return 0;
    return counter(arr,k,n-1,count-1,sum+arr[n-1]) +
            counter(arr,k,n-1,count,sum);
}

int counter1(int arr[],int k, int n){
    if(n<2)
        return 0;
    int freq[n];
    memset(freq,0,sizeof(freq));
    for(int i=0;i<n;i++){
        freq[arr[i] % k] ++;
    }
    int res=0;

    if(freq[0] > 1)
        res= (freq[0] * (freq[0] -1)) /2;

    int i=1, j= k-1;
    while(i<j){
        res = res + freq[i] * freq[j];
        i++;
        j--;
    }

    if(k != 2 && k % 2 ==0){
        res = res + (freq[k/2] * (freq[k/2]-1))/2;
    }
    return res;
}

int main()
 {
	//code
	int tc; cin>>tc;
	while(tc--){
	    int n;cin>>n;
	    int arr[n];
	    for(int i=0; i<n;i++)
	        cin>>arr[i];
	    cout<< counter1(arr,4,n)<<endl;
	    //cout<< counter(arr,4,n,2,0)<<endl;
	}

	return 0;
}
