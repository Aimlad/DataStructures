//CountDistinct

//Using map

void countDistinct(int A[], int k, int n) {
    // Your code here
    unordered_map<int,int> mp;

    for(int i=0;i<k;i++){
        mp[A[i]]++;
    }
    cout<<mp.size()<<" ";

    for(int i=1;i<n-k+1;i++){
        mp[A[i-1]]--;

        if(mp[A[i-1]] <= 0){
            mp.erase(A[i-1]);
        }

        mp[A[i+k-1]]++;
        cout<<mp.size()<<" ";
    }
}


//Using HashTable

void countDistinct(int A[], int k, int n) {
    // Your code here
    if(k<=n){
        int ht[100000];
        int count=0;
        for(int i=0;i<100001;i++)
            ht[i]=0;

        //Initial Count
        for(int i=0;i<k;i++){
            if(ht[A[i]]==0){
                count++;
            }
            ht[A[i]]++;
        }
        cout<<count<<" ";


        //For the rest part of array
        int i=0,j=i+k;
        while(j<n){
            //cout<<"J -> " <<j;
            ht[A[i]]--;
            if(ht[A[i]]==0)
                count--;

            i++;

            if(ht[A[j]]==0){
                count++;

            }

            ht[A[j]]++;
            j++;

            cout<<count<<" ";
        }

    }
    else
        return;
}
