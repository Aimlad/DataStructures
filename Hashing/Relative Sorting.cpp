//Relative Sorting


#include<bits/stdc++.h>
using namespace std;
void swap(int *a,int *b){
  int c=*a;
  *a=*b;
  *b=c;
}
#define MAX 1000001
int hash_table[MAX];
int main()
{
//code
int tc;cin>>tc;
while(tc--){
    int n,m;cin>>n>>m;
    int max_val=0;
    int count=0;
    vector<int> arr1(n);
    vector<int> arr2(m);

      //Initializing hash table to 0
    for(int i=0;i<MAX;i++){
      hash_table[i]=-1;
    }
    //Input for arr1
    for(int i=0;i<n;i++){
        cin>>arr1[i];
    }

    //Input for arr2 and hash table
    for(int i=0;i<m;i++){
        cin>>arr2[i];
        hash_table[arr2[i]]=0;
    }

    //If element present in hash then OK
    // Else push it to the end
    //Keep track of the end
    int i=0,j=n-1;
      while(i<=j){
        if(hash_table[arr1[i]] >=0){
            hash_table[arr1[i]]++;
            count++;
            i++;
        }
        else{
            swap(arr1[i],arr1[j]);
            j--;
        }
    }

    //Using the count in the hash table simply insert values from front in arr1
    i=0;
    for(int j=0;j<m;){
        if(hash_table[arr2[j]]>0){
            arr1[i]=arr2[j];
            hash_table[arr2[j]]-=1;
            i++;
        }
        else{
            j++;
        }
    }


    //Sorting the end part which is not present in arr2
    sort(arr1.begin()+count,arr1.end());

      for(int i=0;i<n;i++){
        cout<<arr1[i]<<" ";
    }
    cout<<endl;
}
return 0;
}

23280666150173
23280666150173
