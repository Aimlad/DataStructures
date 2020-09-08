//Zero Sum Subarrays

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int zerosub(int arr[],int n)
{
    unordered_map<int,int> mp;
    int sum=0;
    int count=0;

    for(int i=0;i<n;i++){
        sum+=arr[i];

        if(sum==0) //Agar 0 aarha hai, to direct add karlo count
            count++;
        /* And agar pichla koi value aa chuka hai
        and abhi sum bhi utna hai, uske index se abhi tk,
        koi aisa subarray hoga, jiska sum 0 tha.*/
        if(mp.find(sum)!=mp.end()){
            count+=mp[sum];
        }

        mp[sum]++;
    }
    return count;

}
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }
	    cout<<zerosub(a,n);
	    cout<<endl;
	}
}
