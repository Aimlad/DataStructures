//Array Pair Sum Divisibility Problem
// Segmentation Fault Geeks
#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	int tc;cin>>tc;
	vector<int> arr(10010);
	map<int,queue<int>> mp;
	while(tc--){
	    int n,k;cin>>n;

	    for(int i=0;i<n;i++)
	        cin>>arr[i];
        cin>>k;

        if(n%2==0){
        for(int i=0;i<n;i++){
            int x = arr[i]%k;
            mp[x].push(arr[i]);
        }

        bool flag=true;
        auto itr=mp.begin();
        while(itr!=mp.end()){
            while(!itr->second.empty()){
                int a=itr->second.front();
                itr->second.pop();

                //cout<<"**"<<k-itr->first<<"**";
                if(mp.find(k-itr->first)!=mp.end() && itr->first!=0){
                    //cout<<a<<"->"<<mp[k-itr->first].front()<<endl;
                    mp[k-itr->first].pop();
                }


                else if(itr->first==0 && mp.find(0)!=mp.end()){
                    //cout<<a<<"->"<<mp[0].front()<<endl;
                    mp[0].pop();
                }


                else{
                    flag=false;
                    break;
                }


            }
            if(flag==false)
                break;
            itr++;
        }
        if(flag==true)
            cout<<"True";
        else
            cout<<"False";
        cout<<endl;
	}
	else{
	    cout<<"False"<<endl;
	}
	mp.clear();
	arr.clear();
	}
	return 0;
}



//**********************************************************************//
// Working code
#include<bits/stdc++.h>
using namespace std;

bool canPairs(vector<int> &arr, int n, int k) 
{
    // An odd length array cannot be divided into pairs
    if (n & 1)
        return false;

    // Create a frequency array to count occurrences
    // of all remainders when divided by k.
    map<int, int> freq;

    // Count occurrences of all remainders
    for (int i = 0; i < n; i++)
        freq[arr[i] % k]++;

    // Traverse input array and use freq[] to decide
    // if given array can be divided in pairs
    for (int i = 0; i < n; i++)
    {
        // Remainder of current element
        int rem = arr[i] % k;

        // If remainder with current element divides
        // k into two halves.
        if  (2*rem == k)
        {
            // Then there must be even occurrences of
            // such remainder
            if (freq[rem] % 2 != 0)
                return false;
        }

        // If remainder is 0, then there must be two
        // elements with 0 remainder
        else if (rem == 0)
        {
           if (freq[rem] & 1)
               return false;
        }

        // Else number of occurrences of remainder
        // must be equal to number of occurrences of
        // k - remainder
        else if (freq[rem] != freq[k - rem])
            return false;
    }
    return true;
}

int main()
 {
	//code
	int tc;cin>>tc;
	while(tc--){
	    int n,k;cin>>n;
	   	vector<int> arr(n);
	    for(int i=0;i<n;i++)
	        cin>>arr[i];
        cin>>k;
        canPairs(arr, n, k)? cout << "True": cout << "False";
        cout<<endl;
	}
	return 0;
}
