//Largest subarray with Sum0

int maxLen(int A[], int n) {
    // Your code here
    unordered_map <int,int> mp;
    int sum=0;
    int cur_count=0;
    int max_count=0;

    for(int i=0;i<n;i++){
        sum+=A[i];
        if(sum==0){ // agar initial se hi 0 arha hai, tab ka case
          //baadme kabhi bhi 0 arha hai, matlab ye h ki start se hi 0 hai.
            max_count=max(max_count,i+1);
        }
        if(mp.count(sum)!=0){
            int x= i- mp[sum];
            if(x>max_count){
                max_count=x;
            }
        }
        else
            mp[sum]=i;

        //cout<<max_count<<" ";
    }

    return max_count;
}
