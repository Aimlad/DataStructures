#include<bits/stdc++.h>
using namespace std;

struct cmp{
    bool operator()(pair<int,int> &p1, pair<int,int> &p2){
        return p1.first>p2.first;
    }
}

int main(){

    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    int k;cin>>k;

    priority_queue<pair<int,int>,vector<pair<int,int>, cmp) pq;
    int i=0;j=0,res=0;
    while(j<n){
        pq.push({arr[j],j});
        if(j-i == k){
            //do something
            while(pq.top().second <= i)
                pq.pop();
            i++;
        }
        res = max(pq.top().first,res);
        j++;
    }
    cout<<res<<endl;
    return 0;
}
